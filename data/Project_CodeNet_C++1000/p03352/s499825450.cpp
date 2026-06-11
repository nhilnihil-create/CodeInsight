#include <bits/stdc++.h>
using namespace std;

bool solve(long long N) {
  if (N == 1) return true;
  for (long long b = 2; b * b <= N; ++b) {
    long long v = b;
    while (v < N) {
      v *= b;
      if (v == N) return true;
    }
  }
  return false;
}

int main() {
  int N;
  cin >> N;
  int res;
  for (int i = N; i >= 1; --i) {
    if (solve(i)) {
      res = i;
      break;
    }
  }
  cout << res << endl;
}