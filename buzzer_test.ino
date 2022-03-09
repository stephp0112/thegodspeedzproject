const int ledPin = 8;
const int buttonPin = 12;
int buttonState = 0;

//defining the notes in the melody
#define NOTE_C4 262
#define NOTE_G3 196
#define NOTE_A3 220
#define NOTE_B3 247
#define NOTE_C4 262

//notes in the melody
int melody[] = {NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};

//note durations. 4=quarter note / 8=eighth note
int noteDurations[] = {4, 8, 8, 4, 4, 4, 4, 4};

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  if (buttonState == 1) {
    digitalWrite(ledPin, HIGH);
    for (int thisNote = 0; thisNote < 8; thisNote++) {
      int noteDuration = 1000 / noteDurations [thisNote];
      tone(2, melody [thisNote], noteDuration);

      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(8);
    }
  }

  if (buttonState == 0) {
    digitalWrite(ledPin, LOW);
  }
}


//  buttonState = digitalRead(buttonPin);
//  if (buttonState == HIGH) {
//    digitalWrite(ledPin, HIGH);
//  } else {
//    digitalWrite(ledPin, LOW);
//  }
//}
