#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;

struct UnionFind {
  vector<int> d;
  UnionFind(int n): d(n,-1) {}
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

int main() {
    int n, m;
    cin >> n >> m;
    vector<P> c(m);
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        c.emplace_back(a,b);
    }
    reverse(c.begin(), c.end());
    UnionFind uf(n);
    vector<ll> ans(m);
    ll mx = (ll)n*(n-1)/2;
    ans[0] = mx;
    rep(i,m-1) {
        int a = c[i].first, b = c[i].second;
        if (uf.same(a,b)) {
            ans[i+1] = ans[i];
            //uf.unite(a,b);
            continue;
        }
        ans[i+1] = ans[i] - ll(uf.size(a))*uf.size(b);
        uf.unite(a,b);
        if (ans[i+1] == 0) break;
    }
    reverse(ans.begin(), ans.end());
    rep(i,m) cout << ans[i] << endl;
    return 0;
}