#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B;
  cin >> A;
  if(A % 2 == 0) {
    B = A / 2;
    cout << B * B << endl;
  }
  else {
    B = (A - 1) / 2;
    cout << B * (B + 1) << endl;
  }
}