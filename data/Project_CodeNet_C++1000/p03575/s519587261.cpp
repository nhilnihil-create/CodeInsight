#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <cassert>
#include <cfloat>
#include <complex>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define repLRE(i, l, r) for (ll i = (l); i <= (r); ++i)
#define rrepLRE(i, l, r) for (ll i = (l); i >= (r); --i)
#define Sort(v) sort(v.begin(), v.end())
#define rSort(v) sort(v.rbegin(), v.rend())
#define Reverse(v) reverse(v.begin(), v.end())
#define Lower_bound(v, x) \
  distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) \
  distance(v.begin(), upper_bound(v.begin(), v.end(), x))

using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
using vll = vector<ll>;
using vP = vector<P>;
using vT = vector<T>;
using vvll = vector<vector<ll>>;
using vvP = vector<vector<P>>;
using dqll = deque<ll>;

ll dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
ll dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};

/* Macros reg. ends here */

const ll INF = 1LL << 50;
struct UnionFind {
  vector<ll> par, sizes;
  ll cnt;
  UnionFind(ll N) : par(N), sizes(N, 1), cnt(N) {
    for (ll i = 0; i < N; i++) par[i] = i;
  }

  ll find(ll x) { return par[x] == x ? x : par[x] = find(par[x]); }

  bool same(ll x, ll y) { return find(x) == find(y); }

  ll size(ll x) { return sizes[find(x)]; }

  void unite(ll x, ll y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (sizes[x] < sizes[y]) swap(x, y);
    par[y] = x;
    sizes[x] += sizes[y];
    cnt--;
  }

  ll count() const { return cnt; }
};
int main() {
  // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);

  ll n, m;
  cin >> n >> m;

  vP es(m);
  rep(i, m) {
    ll a, b;
    cin >> a >> b;
    a--, b--;
    es[i] = {a, b};
  }

  ll ans = 0;
  rep(i, m) {
    UnionFind uf(n);
    rep(j, m) {
      if (i == j) continue;
      uf.unite(es[j].first, es[j].second);
    }
    if (uf.count() != 1) ans++;
  }

  cout << ans << endl;

  return 0;
}
