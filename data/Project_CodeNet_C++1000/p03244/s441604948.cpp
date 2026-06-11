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
  ll n;
  cin >> n;
  vector<vector<ll>> a(2, vector<ll>(1e5, 0));
  REP(i, n) {
    ll x;
    cin >> x;
    x--;
    a[i % 2][x]++;
  }
  vector<vector<P>> p(2);
  REP(i, 1e5) {
    REP(j, 2) { p[j].push_back({i, a[j][i]}); }
  }
  REP(i, 2) {
    sort(ALL(p[i]), [](P x, P y) { return x.second > y.second; });
  }
  ll ans = 1e18;
  REP(i, 2) REP(j, 2) {
    ll x = p[0][i].first, y = p[1][j].first;
    if (x == y) {
      continue;
    }
    ll t = (n / 2 - a[0][x]) + (n / 2 - a[1][y]);
    ans = min(ans, t);
  }
  cout << ans << "\n";
}