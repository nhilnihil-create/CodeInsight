#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> h(n);
  for (int i = 0; i < n; ++i) cin >> h[i];

  vector<ll> dp(n + 105, INF);
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= k; ++j) {
      dp[i + j] = min(dp[i + j], dp[i] + abs(h[i] - h[i + j]));
    }
  }

  cout << dp[n - 1] << '\n';
  return 0;
}
