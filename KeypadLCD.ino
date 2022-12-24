#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

const byte rows = 4;
const byte cols = 4;

char Keys[rows][cols] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[rows] = {9, 8, 7, 6}; 
byte colPins[cols] = {5, 4, 3, 2}; 

Keypad keypad = Keypad(makeKeymap(Keys), rowPins, colPins, rows, cols);
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27,16,2);

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

int a=0;
String inputstr;

void loop() {
  while(a==0){
    char key = keypad.getKey();
    if(key){
      if (key == '0' || key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' || key == 'A' || key == 'B' || key == 'C' || key == 'D'){
        Serial.println(key);
        inputstr += key;
        Serial.println(inputstr);
      }
      else if(key == '#'){
        lcd.print(inputstr);
        a = 1;
      }
      else if(key == '*'){
        inputstr = "";
        lcd.clear();
      }
    }
  }
  a = 0;
}
