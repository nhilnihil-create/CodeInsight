#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const ll INF = 1e18;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<vector<ll>> dp(n, vector<ll>(2, -INF));

  for (int i = 1; i < n; ++i) {
    if (i == 1) {
      dp[1][0] = a[0] + a[1];
      dp[1][1] = -a[0] - a[1];
      continue;
    }
    dp[i][0] = max(dp[i][0], dp[i-1][0] + a[i]);
    dp[i][0] = max(dp[i][0], dp[i-1][1] + a[i]);
    dp[i][1] = max(dp[i][1], dp[i-1][0] - 2 * a[i-1] - a[i]);
    dp[i][1] = max(dp[i][1], dp[i-1][1] + 2 * a[i-1] - a[i]);
  }

  ll ans = max(dp[n-1][0], dp[n-1][1]);
  cout << ans << endl;
  return 0;
}