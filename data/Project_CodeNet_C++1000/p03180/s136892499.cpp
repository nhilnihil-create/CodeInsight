#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
const int INF = 1e9;

ll cost[1 << 16], dp[1 << 16];
int main() {
  ll n;
  cin >> n;
  ll a[n][n];

  rep(i, n) rep(j, n) cin >> a[i][j];

  rep(i, 1 << n) rep(j, n) for (int k = j + 1; k < n;
                                ++k) if (i & (1 << j) && i & (1 << k))
      cost[i] += a[j][k];

  rep(i, 1 << n) for (int j = i; j > 0; j = (j - 1) & i) dp[i] =
      max(dp[i], dp[i - j] + cost[j]);

  cout << dp[(1 << n) - 1] << endl;
  return 0;
}