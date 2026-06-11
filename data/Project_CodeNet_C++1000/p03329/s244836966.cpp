#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, res = 100000;
  cin >> N;
  for (int i = 0; i <= N; i++) {
    int A = i, B = 0;
    while (A != 0) {
      B += A % 9;
      A /= 9;
    }
    A = N - i;
    while (A != 0) {
      B += A % 6;
      A /= 6;
    }
    res = min(res, B);
  }
  cout << res;
  return 0;
}