#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, K;
  cin >> A >> B >> K;
  for (int k = 0; k < K; k++) {
    if (k % 2 == 0) {
      if (A % 2) A--;
      B += A / 2, A /= 2;
    } else {
      if (B % 2) B--;
      A += B / 2, B /= 2;
    }
  }
  cout << A << " " << B << "\n";
}