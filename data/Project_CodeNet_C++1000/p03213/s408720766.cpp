#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define IFOR(i, m, n) for (ll i = n - 1; i >= m; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define FOREACH(x, a) for (auto&(x) : (a))
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

map<ll, ll> prime_decomposition(ll n) {
  map<ll, ll> mp;
  FOR(i, 2, n + 1) {
    ll t = i;
    for (ll p = 2; p * p <= t; p++) {
      if (t % p != 0) continue;
      ll cnt = 0;
      while (t % p == 0) {
        cnt++;
        t /= p;
      }
      mp[p] += cnt;
    }
    if (t != 1) mp[t] += 1;
  }

  return mp;
}

int main() {
  ll n;
  cin >> n;
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  map<ll, ll> mp = prime_decomposition(n);
  // for (auto& x : mp) {
  //   cout << x.first << " " << x.second << endl;
  // }
  ll m = SZ(mp);
  vector<vector<ll>> dp(m + 1, vector<ll>(76, 0));
  dp[0][1] = 1;
  ll i = 0;
  for (auto& x : mp) {
    FOR(j, 1, 76) {
      REP(k, x.second + 1) {
        ll nj = (k + 1) * j;
        if (nj > 75) {
          continue;
        }
        dp[i + 1][nj] += dp[i][j];
      }
    }
    i++;
  }
  // REP(i, m + 1) {
  //   REP(j, 76) {
  //     if (dp[i][j]) {
  //       DUMP(i);
  //       DUMP(j);
  //       DUMP(dp[i][j]);
  //     }
  //   }
  // }
  cout << dp[m][75] << endl;
}