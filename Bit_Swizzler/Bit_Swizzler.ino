
/* 
This program converts the bit order of the items 
in the chargen table defined below into a new bit order
as determined by the oA thru oDp defines to match the
display driving circuitry of a given board.

I'm getting tired of swizzling these by hand so
I'm writing a program to automate the process.

(c) C.Schnarel 2014 ALL RIGHTS RESERVED

 */

// Bit order of output data table
// PC={Dp,F,E,B,G,A,D,C} Segments scrambled to ease PCB layout
#define oA 2
#define oB 4
#define oC 0
#define oD 1
#define oE 5
#define oF 6
#define oG 3
#define oDp 7

// Bit order of input data table
// PC={Dp,G,F,E,D,C,B,A}
#define iA 0
#define iB 1
#define iC 2
#define iD 3
#define iE 4
#define iF 5
#define iG 6
#define iDp 7

// Character generator for 7-segment displays
// PC={Dp,G,F,E,D,C,B,A}
uint8_t	chargen[] = {
0b00111111, // 0
0b00000110, // 1
0b01011011, // 2
0b01001111, // 3
0b01100110, // 4
0b01101101, // 5
0b01111101, // 6
0b00000111, // 7
0b01111111, // 8
0b01101111, // 9
0b01110111, // 10  "A"
0b01111100, // 11  "B"
0b00111001, // 12  "C"
0b01011110, // 13  "D"
0b01111001, // 14  "E"
0b01110001, // 15  "F"
};

char	reverse_chargen[] = {
'0', // 0
'1', // 1
'2', // 2
'3', // 3
'4', // 4
'5', // 5
'6', // 6
'7', // 7
'8', // 8
'9', // 9
'A', // 10  "A"
'B', // 11  "B"
'C', // 12  "C"
'D', // 13  "D"
'E', // 14  "E"
'F', // 15  "F"
};

byte input;
byte output;
int i = 0;

void setup(){
  Serial.begin(115200);
  Serial.println("uint8_t	chargen[] = {");  
  for(i =0;i < sizeof(chargen);i++){
    input = chargen[i];
    output =0;

    if(input & (1<<iA)) output |= (1<<oA);
    if(input & (1<<iB)) output |= (1<<oB);
    if(input & (1<<iC)) output |= (1<<oC);
    if(input & (1<<iD)) output |= (1<<oD);
    if(input & (1<<iE)) output |= (1<<oE);
    if(input & (1<<iF)) output |= (1<<oF);
    if(input & (1<<iG)) output |= (1<<oG);
    if(input & (1<<iDp)) output |= (1<<oDp);

    Serial.print("0b");
    if(output < 128) Serial.print("0");
    if(output < 64) Serial.print("0");
    if(output < 32) Serial.print("0");
    if(output < 16) Serial.print("0");
    if(output < 8) Serial.print("0");
    if(output < 4) Serial.print("0");
    if(output < 2) Serial.print("0");
    Serial.print(output, BIN);
    Serial.print(",  // ");
    Serial.print(i);
    Serial.print("  '");
    Serial.print(reverse_chargen[i]);
    Serial.println("'");
  }
  Serial.println("};");
}

void loop(){
}

/* Here is the rest of the table when we need it.
const prog_uint8_t characterArray[] PROGMEM = {
//  ABCDEFG  Segments
  0b1111110, // 0
  0b0110000, // 1
  0b1101101, // 2
  0b1111001, // 3
  0b0110011, // 4
  0b1011011, // 5
  0b1011111, // 6
  0b1110000, // 7
  0b1111111, // 8
  0b1111011, // 9
  0b1110111, // 10  "A"
  0b0011111, // 11  "B"
  0b1001110, // 12  "C"
  0b0111101, // 13  "D"
  0b1001111, // 14  "E"
  0b1000111, // 15  "F"
  0b0000000, // 16  NO DISPLAY
  0b0000000, // 17  NO DISPLAY
  0b0000000, // 18  NO DISPLAY
  0b0000000, // 19  NO DISPLAY
  0b0000000, // 20  NO DISPLAY
  0b0000000, // 21  NO DISPLAY
  0b0000000, // 22  NO DISPLAY
  0b0000000, // 23  NO DISPLAY
  0b0000000, // 24  NO DISPLAY
  0b0000000, // 25  NO DISPLAY
  0b0000000, // 26  NO DISPLAY
  0b0000000, // 27  NO DISPLAY
  0b0000000, // 28  NO DISPLAY
  0b0000000, // 29  NO DISPLAY
  0b0000000, // 30  NO DISPLAY
  0b0000000, // 31  NO DISPLAY
  0b0000000, // 32 ' '
  0b0000000, // 33 '!'  NO DISPLAY
  0b0100010, // 34 '"'
  0b0000000, // 35 '#'  NO DISPLAY
  0b0000000, // 36 '$'  NO DISPLAY
  0b0000000, // 37 '%'  NO DISPLAY
  0b0000000, // 38 '&'  NO DISPLAY
  0b0100000, // 39 '''
  0b1001110, // 40 '('
  0b1111000, // 41 ')'
  0b0000000, // 42 '*'  NO DISPLAY
  0b0000000, // 43 '+'  NO DISPLAY
  0b0000100, // 44 ','
  0b0000001, // 45 '-'
  0b0000000, // 46 '.'  NO DISPLAY
  0b0000000, // 47 '/'  NO DISPLAY
  0b1111110, // 48 '0'
  0b0110000, // 49 '1'
  0b1101101, // 50 '2'
  0b1111001, // 51 '3'
  0b0110011, // 52 '4'
  0b1011011, // 53 '5'
  0b1011111, // 54 '6'
  0b1110000, // 55 '7'
  0b1111111, // 56 '8'
  0b1111011, // 57 '9'
  0b0000000, // 58 ':'  NO DISPLAY
  0b0000000, // 59 ';'  NO DISPLAY
  0b0000000, // 60 '<'  NO DISPLAY
  0b0000000, // 61 '='  NO DISPLAY
  0b0000000, // 62 '>'  NO DISPLAY
  0b0000000, // 63 '?'  NO DISPLAY
  0b0000000, // 64 '@'  NO DISPLAY
  0b1110111, // 65 'A'
  0b0011111, // 66 'B'
  0b1001110, // 67 'C'
  0b0111101, // 68 'D'
  0b1001111, // 69 'E'
  0b1000111, // 70 'F'
  0b1011110, // 71 'G'
  0b0110111, // 72 'H'
  0b0110000, // 73 'I'
  0b0111000, // 74 'J'
  0b0000000, // 75 'K'  NO DISPLAY
  0b0001110, // 76 'L'
  0b0000000, // 77 'M'  NO DISPLAY
  0b0010101, // 78 'N'
  0b1111110, // 79 'O'
  0b1100111, // 80 'P'
  0b1110011, // 81 'Q'
  0b0000101, // 82 'R'
  0b1011011, // 83 'S'
  0b0001111, // 84 'T'
  0b0111110, // 85 'U'
  0b0000000, // 86 'V'  NO DISPLAY
  0b0000000, // 87 'W'  NO DISPLAY
  0b0000000, // 88 'X'  NO DISPLAY
  0b0111011, // 89 'Y'
  0b0000000, // 90 'Z'  NO DISPLAY
  0b1001110, // 91 '['
  0b0000000, // 92 '\'  NO DISPLAY
  0b1111000, // 93 ']'
  0b0000000, // 94 '^'  NO DISPLAY
  0b0001000, // 95 '_'
  0b0000010, // 96 '`'
  0b1110111, // 97 'a' SAME AS CAP
  0b0011111, // 98 'b' SAME AS CAP
  0b0001101, // 99 'c'
  0b0111101, // 100 'd' SAME AS CAP
  0b1101111, // 101 'e'
  0b1000111, // 102 'f' SAME AS CAP
  0b1011110, // 103 'g' SAME AS CAP
  0b0010111, // 104 'h'
  0b0010000, // 105 'i'
  0b0111000, // 106 'j' SAME AS CAP
  0b0000000, // 107 'k'  NO DISPLAY
  0b0110000, // 108 'l'
  0b0000000, // 109 'm'  NO DISPLAY
  0b0010101, // 110 'n' SAME AS CAP
  0b0011101, // 111 'o'
  0b1100111, // 112 'p' SAME AS CAP
  0b1110011, // 113 'q' SAME AS CAP
  0b0000101, // 114 'r' SAME AS CAP
  0b1011011, // 115 's' SAME AS CAP
  0b0001111, // 116 't' SAME AS CAP
  0b0011100, // 117 'u'
  0b0000000, // 118 'b'  NO DISPLAY
  0b0000000, // 119 'w'  NO DISPLAY
  0b0000000, // 120 'x'  NO DISPLAY
  0b0000000, // 121 'y'  NO DISPLAY
  0b0000000, // 122 'z'  NO DISPLAY
  0b0000000, // 123 '0b'  NO DISPLAY
  0b0000000, // 124 '|'  NO DISPLAY
  0b0000000, // 125 ','  NO DISPLAY
  0b0000000, // 126 '~'  NO DISPLAY
  0b0000000, // 127 'DEL'  NO DISPLAY
};

*/

