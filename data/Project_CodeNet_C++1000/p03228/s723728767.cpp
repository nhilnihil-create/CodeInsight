#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, K = 0;
  cin >> A >> B >> K;
  for (int i=0; i < K; i++) {
    if (i%2 == 0) {
      A /= 2;
      B += A;
    } else {
      B /= 2;
      A += B;
    }
  }
  cout << A << ' ' << B << endl;
}