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

int main() {
  ll n, c;
  cin >> n >> c;
  vector<vector<ll>> a(3, vector<ll>(c, 0)), d(c, vector<ll>(c));
  REP(i, c) REP(j, c) { cin >> d[i][j]; }
  REP(i, n) {
    REP(j, n) {
      ll x;
      cin >> x;
      x--;
      a[(i + j) % 3][x]++;
    }
  }
  ll ans = 1e18;
  REP(i, c) REP(j, c) REP(k, c) if (i != j && i != k && j != k) {
    ll t = 0;

    REP(m, c) {
      t += a[0][m] * d[m][i];
      t += a[1][m] * d[m][j];
      t += a[2][m] * d[m][k];
    }
    ans = min(ans, t);
  }
  cout << ans << endl;
}