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
  ll n, m, Q;
  cin >> n >> m >> Q;
  vector<vector<ll>> a(n + 1, vector<ll>(n + 1, 0));
  REP(i, m) {
    ll l, r;
    cin >> l >> r;
    a[l][r]++;
  }
  REP(i, n + 1) {
    REP(j, n) { a[i][j + 1] += a[i][j]; }
  }
  REP(j, n + 1) {
    REP(i, n) { a[i + 1][j] += a[i][j]; }
  }

  // REP(i, n + 1) {
  //   REP(j, n + 1) { cout << a[i][j] << " \n"[j == n]; }
  // }

  while (Q--) {
    ll p, q;
    cin >> p >> q;
    cout << a[n][q] - a[p - 1][q] << endl;
  }
}