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
  ll n, k;
  cin >> n >> k;
  vector<ll> p, m;
  p.push_back(0);
  m.push_back(0);
  REP(i, n) {
    ll a;
    cin >> a;
    if (a >= 0) {
      p.push_back(a);
    } else {
      m.push_back(-a);
    }
  }
  sort(ALL(p));
  sort(ALL(m));

  ll ans = 1e18;
  REP(i, min(k + 1, SZ(p))) {
    if (k - i >= SZ(m)) {
      continue;
    }
    ll t1 = p[i];
    ll t2 = m[k - i];
    ll t = min(t1 + 2 * t2, 2 * t1 + t2);
    ans = min(ans, t);
  }
  cout << ans << endl;
}