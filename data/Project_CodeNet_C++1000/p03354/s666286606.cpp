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
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    rep(i,n) p[i]--;
    UnionFind uf(n);
    rep(i,m) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        uf.unite(x,y);
    }
    int ans = 0;
    rep(i,n) {
        if (uf.same(p[i],i)) ans++;
    }
    cout << ans << endl;
    return 0;
}