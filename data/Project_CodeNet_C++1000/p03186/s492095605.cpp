#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C;
  cin >> A >> B >> C;
  if (C <= A + B) {
    cout << C + B << endl;
  }
  else if (C == A + B) {
    cout << B + A + B << endl;
  }
  else if (C > A + B) {
    cout << B + A + B + 1 << endl;
  }
}