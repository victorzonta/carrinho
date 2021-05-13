#include <Arduino.h>
#include <SoftwareSerial.h>
SoftwareSerial bluetooth(0,1);
#define IN_1 8 // sentido do motor
#define IN_2 7 // sentido do motor
#define EN_A 5 // velocidade de rotacao
#define EN_B 6 // velocidade de rotacao
#define LUZ 10 //luz da frente

void LUZA (){
  digitalWrite(LUZ, HIGH);
}
void LUZD (){
  digitalWrite(LUZ, LOW);
}

void parar (){
   digitalWrite(EN_A, LOW);
   digitalWrite(EN_B, LOW);
 } 

void frente(){
   digitalWrite(EN_A, HIGH);
   digitalWrite(EN_B, HIGH);
   digitalWrite(IN_1, LOW);
   digitalWrite(IN_2, LOW);
   }

void tras(){
   digitalWrite(EN_A, HIGH);
   digitalWrite(EN_B, HIGH);
   digitalWrite(IN_1, HIGH);
   digitalWrite(IN_2, HIGH);
 
}

void direita(){
   digitalWrite(EN_A, HIGH);
   digitalWrite(EN_B, LOW);
   digitalWrite(IN_1, HIGH);
   digitalWrite(IN_2, LOW);
  
}

void esquerda(){
   digitalWrite(EN_A, LOW);
   digitalWrite(EN_B, HIGH);
   digitalWrite(IN_1, LOW);
   digitalWrite(IN_2, HIGH);
  
}

void tras_esquerda(){
   digitalWrite(IN_1, HIGH);
   digitalWrite(IN_2, LOW);
   digitalWrite(EN_B, HIGH);
   digitalWrite(EN_A, LOW);
  
}
 void tras_direita(){
   digitalWrite(IN_1, LOW);
   digitalWrite(IN_2, HIGH);
   digitalWrite(EN_B, LOW);
   digitalWrite(EN_A, HIGH);
  
}

void setup() {
   pinMode (IN_1, OUTPUT);
   pinMode (IN_2, OUTPUT);
   pinMode (EN_A, OUTPUT);
   pinMode (EN_B, OUTPUT);
   pinMode (LUZ, OUTPUT);
   Serial.begin(9600);
   bluetooth.begin(9600);
}

void loop() {
  if(Serial.available()) {
    char x =Serial.read();
    Serial.println(x);
    switch(x){
      case 'F':
        frente();
        break;
      case 'B':
        tras();       
        break;
      case 'R':
        direita();        
        break;
      case 'L':
        esquerda();
        break;
      case 'G':
        esquerda();
        break;
      case 'I':
        direita();
        break;
      case 'H':
        tras_esquerda();        
        break;
      case 'J':
        tras_direita();
        break;
      case 'S':
       parar();
       break;
      default:
      parar();
      break;
      case 'W':
      LUZA();
      break;
      case 'w':
      LUZD();
      break;
    }// fim switch
  }// fim if

}// fim loop 