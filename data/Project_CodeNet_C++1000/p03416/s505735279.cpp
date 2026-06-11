#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  
  int a1 = A / 10000, a2 = (A / 1000) % 10, a3 = (A / 100) % 10;
  int b1 = B / 10000, b2 = (B / 1000) % 10, b3 = (B / 100) % 10;
  
  int C, D;
  C = 10001 * a1 + 1010 * a2 + 100 * a3;
  D = 10001 * b1 + 1010 * b2 + 100 * b3;
  
  if (A > C) {
    if (a3 < 9) {
      a3++;
    }
    else if (a3 == 9 && a2 < 9) {
      a3 = 0, a2++;
    }
    else {
      a1++, a2 = 0, a3 = 0;
    }
  }
  
  if (B < D) {
    if (b3 > 0) {
     b3--;
    }
    else if (b3 == 0 && b2 > 0) {
      b3 = 9, b2--;
    }
    else {
      b3 = 9, b2 = 9, b1--;
    }
  }
  cout << 100 * (b1 - a1) + 10 * (b2 - a2) + (b3 - a3) + 1 << endl;
}