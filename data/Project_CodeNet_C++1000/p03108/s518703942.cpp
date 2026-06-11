#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

struct UnionFind {
  vector<int> d;
  UnionFind(int n=0): d(n,-1) {}
  int find(int x) {
    if (d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  bool unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y);}
  int size(int x) { return -d[find(x)];}
};

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m+1), b(m+1);
    rep(i, m) cin >> a[i+1] >> b[i+1];

    vector<ll> ans(m+1);
    ans[m] = n * (n-1) / 2;
    UnionFind uf = UnionFind(n+1);
    for (int i = m; i > 0; i--) {
        if (!uf.same(a[i], b[i])) {
            ans[i-1] = ans[i] - uf.size(a[i]) * uf.size(b[i]);
            uf.unite(a[i], b[i]);
        } else {
            ans[i-1] = ans[i];
        }
    }

    rep(i, m) cout << ans[i+1] << endl;
}

int main() {
    solve();
    return 0;
}
