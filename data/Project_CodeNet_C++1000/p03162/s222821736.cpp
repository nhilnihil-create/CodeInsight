#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define erep(i, n) for (ll i = 1; i <= (n); i++)
#define maxs(x, y) (x = max(x, y))
#define mins(x, y) (x = min(x, y))
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
// input
ll h[100010][3];
// dp table
ll dp[100010][3];

int main(void) {
  int n;
  cin >> n;
  rep(i, n) rep(j, 3) cin >> h[i][j];
  rep(i, n) rep(j, 3) rep(k, 3) if (j != k) {
    maxs(dp[i + 1][j], dp[i][k] + h[i][j]);
  }
  ll ans = 0;
  rep(i, 3) maxs(ans, dp[n][i]);
  cout << ans << '\n';
  return 0;
}