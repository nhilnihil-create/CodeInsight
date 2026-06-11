#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

//Union Find
struct UnionFind {
  vector<int> par; // 親ノード
  vector<int> rank; // ランク

  UnionFind(int n = 1) {
    init(n);
  }
  void init(int n = 1) {
    par.resize(n); rank.resize(n);
    for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 0;
  }
  int root(int x) {
    if (par[x] == x) {
    return x;
  }
    else {
      int r = root(par[x]);
      return par[x] = r;
    }
  }
  bool issame(int x, int y) {
    return root(x) == root(y);
  }

  bool merge(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return false;
    if (rank[x] < rank[y]) swap(x, y);
    if (rank[x] == rank[y]) ++rank[x];
    par[y] = x;
    return true;
  }
};

int main() {
  int N,M,x,y;
  cin >> N >> M;
  vector<int> p(N);
  rep(i,N) cin >> p[i];
  UnionFind uf(N+1);
  rep(i,M) {
    cin >> x >> y;
    uf.merge(x,y);
  }

  int ans=0;
  rep2(i,1,N+1) {
    int t = p[i-1];
    if (uf.issame(t,i)) ans++;
  }
  cout << ans << endl;
}