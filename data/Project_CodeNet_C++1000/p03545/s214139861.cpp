#include <bits/stdc++.h>
using namespace std;
int main() {
  int memo, A, B, C, D;
  cin >> memo;
  A = memo / 1000;
  B = (memo % 1000) / 100;
  C = (memo % 100) / 10;
  D = memo % 10;
  for (int tmp = 0; tmp < (1 << 3); tmp++) {
    bitset<3> s(tmp);
    int memo2 = A;
    if (s.test(0)) {
      memo2 += B;
    }
    else {
      memo2 -= B;
    }
    if (s.test(1)) {
      memo2 += C;
    }
    else {
      memo2 -= C;
    }
    if (s.test(2)) {
      memo2 += D;
    }
    else {
      memo2 -= D;
    }
    if (memo2 == 7) {
      cout << A;  
      if (s.test(0)) {
        cout << "+";
      }
      else {
        cout << "-";
      }
      cout << B;  
      if (s.test(1)) {
        cout << "+";
      }
      else {
        cout << "-";
      }
      cout << C;  
      if (s.test(2)) {
        cout << "+";
      }
      else {
        cout << "-";
      }
      cout << D << "=7" << endl;
      break;
    }
  }
}