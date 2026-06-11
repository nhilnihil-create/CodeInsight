#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  
  if (A >= B && B >= C || A >= C && A >= B) {
    cout << A * 10 + B + C<< endl;
  } else if (B >= A && A >= C || B >= C && C >= A) {
    cout << B * 10 + A + C << endl;
  } else if (C >= A && A >= B || C >= B && B >= A) {
    cout << C * 10 + A + B << endl;
  }
}