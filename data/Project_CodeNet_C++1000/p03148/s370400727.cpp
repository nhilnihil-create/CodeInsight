#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "dump.hpp"
#else
#define dump(...)
#define dumpv(...)
#endif

#define rep(i, n) for (int i = 0; i < (n); i++)
#define mins(x, y) (x = min(x, y))
#define maxs(x, y) (x = max(x, y))
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
const int MOD = 1e9 + 7;
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;

void solve() {
  int n, k;
  cin >> n >> k;
  vvi a(n);
  rep(i, n) {
    int t, d;
    cin >> t >> d;
    a[--t].push_back(d);
  }
  rep(i, n) sort(a[i].begin(), a[i].end(), greater<int>());
  vector<P> p;
  rep(i, n) {
    if (a[i].size() > 0) p.push_back(P(a[i][0], 1));
  }
  rep(i, n) {
    for (int j = 1; j < a[i].size(); j++) p.push_back(P(a[i][j], 0));
  }
  sort(p.begin(), p.end(), greater<P>());
  dump(p);
  ll sum1 = 0;
  ll sum2 = 0;
  ll nk = 0;
  vector<int> q;
  rep(i, k) {
    sum1 += p[i].first;
    nk += p[i].second;
    if (!p[i].second) q.push_back(p[i].first);
  }
  sum2 = nk * nk;
  int idx = k;
  ll ans = sum1 + sum2;
  while (nk < k && idx < n && q.size() > 0) {
    dump(ans, sum1, sum2, idx, nk, q);
    for (; idx < n; idx++) {
      if (p[idx].second) {
        nk++;
        sum2 = nk * nk;
        sum1 += p[idx].first - q.back();
        q.pop_back();
        maxs(ans, sum1 + sum2);
        idx = idx + 1;
        break;
      }
    }
  }
  dump(ans, sum1, sum2, idx, nk, q);
  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  // freopen("temp.1", "r", stdin);
  solve();
  return 0;
}