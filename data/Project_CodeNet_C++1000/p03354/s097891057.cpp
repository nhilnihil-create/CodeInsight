#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; ++i)
using ll = long long;
const ll MOD = 1000000007;//998244353;
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
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n, m; cin >> n >> m;
   UnionFind uf(n);
   vector<int> p(n);
   rep(i,n){
      cin >> p[i];
      p[i]--;
   }
   rep(i,m){
      int x,y; cin >> x >> y;
      x--;y--;
      uf.unite(x,y);
   }
   int ans = 0;
   rep(i,n)
      ans += (uf.same(i,p[i]));
   cout << ans << endl;
}