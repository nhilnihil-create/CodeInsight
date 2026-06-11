#include <bits/stdc++.h>

#define fi first
#define se second
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define vll vector<ll>
#define vpll vector<pair<ll,ll>>
#define endl '\n'

#define si(v) int(v.size())
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep2(i, n, m) for (ll i = n; i <= (m); ++i)
#define rep3(i, n, m) for (ll i = n; i >= (m); --i)

template<class T, class U> void chmax(T &a, U b) { if (a < b) a = b; }
template<class T, class U> void chmin(T &a, U b) { if (b < a) a = b; }

using ll = long long;
using ld = long double;
using namespace std;

constexpr ll MOD = 1000000007;

struct UnionFind {
  vector<int> par, siz;

  UnionFind(int n) : par(n), siz(n, 1) {
    for (int i = 0; i < n; ++i) par[i] = i;
  }

  int root(int x) {
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
  }

  bool unite(int x, int y) {
    x = root(x);
    y = root(y);

    if (x == y) return false;

    if (siz[x] < siz[y]) swap(x, y);
    siz[x] += siz[y];
    par[y] = x;
    return true;
  }

  bool same(int x, int y) {
    return root(x) == root(y);
  }

  int size(int x) {
    return siz[x];
  }
};

signed main()
{
  cout << fixed << setprecision(20);
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m; cin >> n >> m;
  vpi edge(m);

  rep(i, m) cin >> edge[i].fi >> edge[i].se;

  int ans = 0;
  rep(i, m) {
    UnionFind uf(n);
    
    rep(j, m) {
      if (i == j) continue;
      uf.unite(edge[j].fi-1, edge[j].se-1);
    }

    bool connect = true;
    rep(i, n-1) if (!uf.same(i, i+1)) connect = false;

    if (!connect) ++ans;
  }

  cout << ans << endl;
  
  return (0);
}