#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, B, C, D;
  string word;
  cin >> word;
  A = (word.at(0) - '0');
  B = (word.at(1) - '0');
  C = (word.at(2) - '0');
  D = (word.at(3) - '0');
  
  int total;
  char op1, op2, op3;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        total = 0;
        if (i == 0) {
          total = A + B;
        }
        else {
          total = A - B;
        }
        if (j == 0) {
          total += C;
        }
        else {
          total -= C;
        }
        if (k == 0) {
          total += D;
        }
        else {
          total -= D;
        }
        if (total == 7) {
          if (i == 0) {
            op1 = '+';
          }
          else {
            op1 = '-';
          }
          if (j == 0) {
            op2 = '+';
          }
          else {
            op2 = '-';
          }
          if (k == 0) {
            op3 = '+';
          }
          else {
            op3 = '-';
          }
        }
      }
    }
  }
  cout << A << op1 << B << op2 << C << op3 << D << "=7" << endl;
  
  return 0;
}