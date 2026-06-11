#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  int C = N*A;

  if (B == C) {
    cout << C  << endl;
  }

  else if (B > C) {
    cout << C  << endl;
  }

  else if (B < C) {
    cout << B << endl;
  }

}