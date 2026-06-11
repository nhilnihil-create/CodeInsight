#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}

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
  int N,M,x,y,z;
  cin >> N >> M;
  vector<vector<int>> g(N);
  vector<int> ans(N,-1);
  UnionFind uf(N);

  rep(i,M) {
    cin >> x >> y >> z;
    x--;y--;
    if (z%2==2) {
      ans[x] = ans[y] = 2;
    }
    uf.merge(x,y);
  }
  set<int> known;
  map<int,int> m;
  rep(i,N) {
    if (ans[i]==2) known.insert(uf.root(i));
    m[uf.root(i)]++;
  }
  int cnt=0;
  
  for (auto i=m.begin();i!=m.end();i++) {
    if (known.find(i->first)!=known.end()) continue;
    else {
      auto tmp = i->second;
      cnt++;
    }
  }
  cout << cnt << endl;
}