#include <bits/stdc++.h>
using namespace std;

int main() {
  long N, K;
  cin >> N >> K;
  vector<long> X(N);
  for (long i = 0; i < N; i++) cin >> X.at(i);
  long ans = 2e18;
  for (long i = 0; i + K - 1 < N; i++) {
    long l = X.at(i);
    long r = X.at(i + K - 1);
    if (r < 0) ans = min(ans, -l);
    else if (l > 0) ans = min(ans, r);
    else ans = min(ans, r - l + min(-l, r));
  }
  cout << ans << "\n";
}