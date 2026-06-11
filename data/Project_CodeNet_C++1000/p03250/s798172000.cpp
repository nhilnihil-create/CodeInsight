#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  if (A >= B && A >= C) {
    cout << A * 10 + B + C << endl;
  }
  else if (B >= A && B >= C) {
    cout << B * 10 + A + C << endl;
  }
  else {
    cout << C * 10 + A + B << endl;
  }
}