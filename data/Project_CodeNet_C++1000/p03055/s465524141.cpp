#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<ll, ll> PLL;
#define chmax(x, y) do { x = max(x, y); } while(0)
#define chmin(x, y) do { x = min(x, y); } while(0)
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) \
  for (ll i = static_cast<ll>(a); i < static_cast<ll>(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, ) (__VA_ARGS__)  // NOLINT
template<typename T>
using reversed_priority_queue = std::priority_queue<T, std::vector<T>, std::greater<T> >;

ll N;
vector<ll> edges[300000];

// 頂点 cur から最も遠い点に対して {vへの距離、v} を調べる
PLL f(ll cur, ll par = -1, ll d = 0) {
  if (edges[cur].size() == 1 && edges[cur][0] == par)
    return {d, cur};
  PLL res(-1, -1);
  for (auto nxt : edges[cur]) {
    if (nxt == par) continue;
    chmax(res, f(nxt, cur, d+1));
  }
  return res;
}

signed main() {
  cin >> N;
  rep(i, N-1) {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  if (N == 1) {
    cout << "First" << endl;
    return 0;
  }
  ll u, r, _, __;
  tie (_, u) = f(0);
  tie (r, __) = f(u);
  cout << (r % 3 != 1 ? "First" : "Second") << endl;
  return 0;
}
