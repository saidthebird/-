#include<Stepper.h>

int move =0;
 int fff=0;

Stepper stepper(1000,8,9,10,11);

void setup()
{
  Serial.begin(9600);
  pinMode(A1,INPUT);
  pinMode(2, INPUT);
  pinMode(12,OUTPUT);

  stepper.setSpeed(13);
}

void loop()
{
  int adc = analogRead(A1);

  if(adc>200)
  {
    unsigned long firstTime = millis();

    for(unsigned long lastTime = millis(); lastTime-firstTime >1000;lastTime = millis())
    {
       fff = analogRead(A1);
    }
  }
  
  if(adc>200)
  {
  Serial.println(adc);
   Serial.println(fff);
  }
 

  int off = digitalRead(2);

  if(off == 0)
  {
      stepper.step(false);
     move = 0;
     digitalWrite(12,LOW);
  }

  if(adc>200||move>100)
  {
    stepper.step(true);
    move =101;
  }

  if(fff>200)
  {
  digitalWrite(12,HIGH);
  }
}
