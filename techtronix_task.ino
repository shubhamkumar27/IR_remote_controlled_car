#include <IRremote.h>  //including IRremote library file

int ir = 12; //connecting data pin of reciever to pin 12 of arduino
IRrecv recieve(ir);
decode_results code;
int lm1 = 4; //left motor pin 1
int lm2 = 5; //left motor pin 2
int rm1 = 6; //right motor pin 1
int rm2 = 7; //right motor pin 2

void setup() {
  recieve.enableIRIn();
  pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
}

void loop() {
  if(recieve.decode(&code)){
    switch(code.value){
      //BACK
      case 0xFF58A7: digitalWrite(lm1,LOW);
                     digitalWrite(lm2,HIGH);
                     digitalWrite(rm1,LOW);
                     digitalWrite(rm2,HIGH);
                     break;
      //FORWARD
      case 0xFF708F: digitalWrite(lm2,LOW);
                     digitalWrite(lm1,HIGH);
                     digitalWrite(rm2,LOW);
                     digitalWrite(rm1,HIGH);
                     break;
      //LEFT
      case 0xFF50AF: digitalWrite(lm1,LOW);
                     digitalWrite(lm2,HIGH);
                     digitalWrite(rm2,LOW);
                     digitalWrite(rm1,HIGH);
                     break;
      //RIGHT
      case 0xFF7887: digitalWrite(lm2,LOW);
                     digitalWrite(lm1,HIGH);
                     digitalWrite(rm1,LOW);
                     digitalWrite(rm2,HIGH);
                     break;
      //STOP
      case 0xFFA05F: digitalWrite(lm1,LOW);
                     digitalWrite(lm2,LOW);
                     digitalWrite(rm1,LOW);
                     digitalWrite(rm2,LOW);
                     break;
    }
    recieve.resume();  //ready to recieve next code
  }
}
