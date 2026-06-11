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

ll n;
vector<ll> a(3), l, g;
ll ans = 1e18;

void calc() {
  ll cost = 0;
  REP(i, 3) {
    ll sum = 0, sz = 0;
    REP(j, n) {
      if (g[j] != i) {
        continue;
      }
      sz++;
      sum += l[j];
    }
    if (sz == 0) {
      return;
    }
    cost += 10 * (sz - 1) + abs(sum - a[i]);
  }
  ans = min(ans, cost);
}

void dfs() {
  if (SZ(g) == n) {
    calc();
    return;
  }

  REP(i, 4) {
    g.push_back(i);
    dfs();
    g.pop_back();
  }
}

int main() {
  cin >> n;
  l = vector<ll>(n);
  REP(i, 3) { cin >> a[i]; }
  REP(i, n) { cin >> l[i]; }
  dfs();
  cout << ans << "\n";
}