#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
using namespace std;
typedef long long ll;

struct UnionFind {
  vector<int> par;

  UnionFind(int n) : par(n, -1) { }

  int root(int x) {
    if (par[x] < 0) return x;
    else return par[x] = root(par[x]);
  }

  bool same(int x, int y) {
    return root(x) == root(y);
  }

  bool merge(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return false;

    if (par[x] > par[y]) swap(x, y);
    par[x] += par[y];
    par[y] = x;

    return true;
  }

  int size(int x) {
    return -par[root(x)];
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N,M;
  cin >> N >> M;

  UnionFind uf(N+1);
  
  vector<int> P(N);
  rep(i, N) cin >> P[i];

  rep(i, M) {
    int x,y; cin >> x >> y;
    uf.merge(x, y);
  }

  int ans = 0;
  rep(i, N) {
    if(uf.same(P[i], i + 1)) {
      ans++;
    }
  }

  cout << ans << endl;
}
