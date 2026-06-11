#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;

struct UnionFind {
  vector<int> par; //親の番号
  UnionFind(int N) : par(N) {
    rep(i, N) par[i] = i;
  }

  int find(int x){
    if(par[x] == x) return x;
    return find(par[x]);
  }

  void unite(int x, int y){
    int rx = find(x);
    int ry = find(y);
    if(rx == ry) return;
    if(par[rx] > par[ry]) swap(rx, ry);
    par[ry] = rx;
  }

  bool same(int x, int y){
    int rx = find(x);
    int ry = find(y);
    return find(rx) == find(ry);
  }
};

int main(){
  int N, M;
  cin >> N >> M;
  vector<int> p(N);
  rep(i, N){
    cin >> p[i];
  }
  UnionFind uf(N);
  int x, y;
  rep(i, M){
    cin >> x >> y;
    x--; y--;
    if(!uf.same(x, y)){
      uf.unite(x, y);
    }
  }
  int ans = 0;
  rep(i, N){
    if(uf.same(i, p[i]-1)){
      ans++;
    }
  }
  cout << ans << endl;
}
