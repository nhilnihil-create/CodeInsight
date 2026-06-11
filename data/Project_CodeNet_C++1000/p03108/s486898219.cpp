#include <bits/stdc++.h>
#define int long long
#pragma GCC optimize("O3")

#define fi first
#define se second
#define em emplace
#define eb emplace_back
#define mp make_pair
#define pi pair<int,int>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define vll vector<ll>
#define vpll vector<pair<ll,ll>>
#define endl '\n'

#define si(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i) 
#define rep2(i, n, m) for (ll i = n; i <= (ll)(m); ++i)
#define rep3(i, n, m) for (ll i = n; i >= (ll)(m); --i)

template<class T, class U> bool chmax(T &a, U b) { if (a < b) a = b; return true; }
template<class T, class U> bool chmin(T &a, U b) { if (a > b) a = b; return true; }

using ll = long long;
using ld = long double;
using namespace std;

constexpr ll MOD = 1000000007;

template<class T>
struct UnionFind {
  vector<T> parent, siz;

  UnionFind(int n) : parent(n), siz(n) {
    for (int i = 0; i < n; ++i) {
      parent[i] = i;
      siz[i] = 1;
    }
  }

  T root(T x)
  {
    if (parent[x] == x) return x;
    return parent[x] = root(parent[x]);
  }

  bool unite(T x, T y)
  {
    x = root(x);
    y = root(y);

    if (x == y) return false;

    if (siz[x] < siz[y]) swap(x, y);
    parent[y] = x;
    siz[x] += siz[y];

    return true;
  }

  bool same(T x, T y)
  {
    return root(x) == root(y);
  }

  T size(T x)
  {
    return siz[root(x)];
  }
};

signed main()
{
  cout << fixed << setprecision(20);
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m; cin >> n >> m;
  vpi edge(m);

  UnionFind<int> uf(n);

  rep(i, m) cin >> edge[i].fi >> edge[i].se, --edge[i].fi, --edge[i].se;
  reverse(all(edge));

  ll val = n * (n - 1) / 2;
  vi ans;

  ans.eb(val);

  rep(i, m-1) {
    if (!uf.same(edge[i].fi, edge[i].se)) {
      val -= uf.size(edge[i].fi) * uf.size(edge[i].se);
      uf.unite(edge[i].fi, edge[i].se);
    }
    ans.eb(val);
  }

  reverse(all(ans));
  rep(i, m) cout << ans[i] << endl;

  return (0);
}
