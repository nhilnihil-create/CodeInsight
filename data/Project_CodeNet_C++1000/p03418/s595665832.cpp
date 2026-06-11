#include <bits/stdc++.h>

using namespace std;

int main() {
  long long N, K;
  cin >> N >> K;
  long long ans = 0;
  for (int i = K + 1; i <= N; i++) {
    long long ci = K == 0 ? 0 : N / i * K + min(N % i, K - 1);
    ans += N - ci;
  }
  cout << ans << endl;

  return 0;
}
/* vim:set fdm=marker: */
