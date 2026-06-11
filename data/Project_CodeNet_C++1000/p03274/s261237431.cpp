#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  int x[N];
  for (int i = 0; i < N; i++) {
    cin >> x[i];
  }
  int ans = INT_MAX, foo;
  for (int i = 0; i < N - K + 1; i++) {
    if (x[i] >= 0) {
      foo = x[i + K - 1];
    }
    else if (x[i + K - 1] < 0) {
      foo = -x[i];
    }
    else {
      foo = x[i + K - 1] - x[i] + min(x[i + K - 1], -x[i]);
    }
    if (foo < ans) {
      ans = foo;
    }
  }
  cout << ans;
  return 0;
}