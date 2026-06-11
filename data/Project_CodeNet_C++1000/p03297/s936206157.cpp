#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    long long int A, B, C, D;
    cin >> A >> B >> C >> D;
    if (B > A || B > D)
      cout << "No" << endl;
    else {
      long long int g = __gcd(B, D);
      if (A % B + (B - A % B - 1) / g * g <= C) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }
}