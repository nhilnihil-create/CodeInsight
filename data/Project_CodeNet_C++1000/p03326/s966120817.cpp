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

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> x(3, vector<ll>(n));

  REP(j, n) REP(i, 3) { cin >> x[i][j]; }

  const ll INF = 1e18;
  ll ans = -INF;
  REP(bit, (1LL << 3)) {
    vector<ll> c(3, 1);
    REP(i, 3) {
      if (bit & (1LL << i)) {
        c[i] = -1;
      }
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, -INF));
    dp[0][0] = 0;
    REP(i, n) REP(j, m + 1) if (dp[i][j] != -INF) {
      chmax(dp[i + 1][j], dp[i][j]);
      if (j + 1 <= m) {
        ll ad = 0;
        REP(k, 3) { ad += c[k] * x[k][i]; }
        chmax(dp[i + 1][j + 1], dp[i][j] + ad);
      }
    }

    ans = max(ans, dp[n][m]);
  }
  cout << ans << endl;
}