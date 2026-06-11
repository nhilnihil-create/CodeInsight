#include <iostream>

using namespace std;

int main() {
  char c;
  cin >> c;
  switch(c) {
    case('A'):
      cout << 'T' << endl;
      break;
    case('T'):
      cout << 'A' << endl;
      break;
    case('C'):
      cout << 'G' << endl;
      break;
    case('G'):
      cout << 'C' << endl;
      break;
  }
}