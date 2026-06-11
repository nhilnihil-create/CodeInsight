#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K, x;
  cin >> N >> K;
  x = 1;
  for (int i = 0; i < N; i++) {
    int A, B;
    A = x * 2;
    B = x + K;
    if (A <= B) {
      x *=2;
    }
    else {
      x += K;
    }
  }
  cout << x << endl;
}
