#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define erep(i, n) for (ll i = 1; i <= (n); i++)
#define maxs(x, y) (x = max(x, y))
#define mins(x, y) (x = min(x, y))
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
// input
ll h[100010];
// dp table
ll dp[100010];

int main(void) {
  int n, k;
  cin >> n >> k;
  rep(i, n) cin >> h[i];
  rep(i, 100010) dp[i] = INF;
  dp[0] = 0;
  rep(i, n) erep(j, k) { mins(dp[i + j], dp[i] + abs(h[i] - h[i + j])); }
  cout << dp[n - 1] << '\n';
  return 0;
}