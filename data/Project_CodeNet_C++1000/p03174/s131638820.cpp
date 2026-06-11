#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

const int mod = 1000000007;
ll dp[22][1 << 22];
ll a[22][22];

int main() {
  ll n, ans = 0;
  cin >> n;
  rep(i, n) rep(j, n) cin >> a[i][j];

  dp[0][0] = 1;
  rep(msk, 1 << n) rep(i, n) if (i == __builtin_popcount(msk))
      rep(j, n) if (!(msk & 1 << j) && a[i][j])
        (dp[i + 1][msk | 1 << j] += dp[i][msk]) %= mod;


  cout << dp[n][(1 << n) - 1] << endl;
  return 0;
}
