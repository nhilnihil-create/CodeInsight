#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  vector<vector<ll>> dp(n + 1, vector<ll>(2, -1));

  dp[0][0] = 0;
  dp[0][1] = -1e18;
  rep(i, n) {
    dp[i + 1][0] = max(dp[i][0] + a[i], dp[i][1] - a[i]);
    dp[i + 1][1] = max(dp[i][0] - a[i], dp[i][1] + a[i]);
  }
  cout << dp[n][0] << endl;
  // rep(i, n) cerr << dp[i][0] << " " << dp[i][1] << endl;
  return 0;
}
