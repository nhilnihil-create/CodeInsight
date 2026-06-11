#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
using ll = long long;

struct UnionFind{
  vector<int> p;
  vector<int> r;
  vector<int> g;
  UnionFind(int n){
    p.resize(n,-1);
    r.resize(n,1);
    g.resize(n,1);
  }
  int find(int x){
    if(p[x] == -1) return x;
    else return p[x] = find(p[x]);
  }
  void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(r[x] > r[y]) swap(x,y);
    if(r[x] == r[y]) ++r[y];
    g[y] += g[x];
    p[x] = y;
  }
  int gsize(int x){
    return g[find(x)];
  }
};

int main(){
  int n, m;
  cin >> n >> m;
  vector<P> vec(m);
  for(int i=0; i<m; ++i){
    int a, b;
    cin >> a >> b;
    --a; --b;
    vec[i] = make_pair(a,b);
  }
  ll ansnum = (ll)n * ((ll)n-1) /2;
  vector<ll> ans(m);
  ans[m-1] = ansnum;
  UnionFind uf(n);
  for(int i=m-1; i>0; --i){
    int ai = vec[i].first, bi = vec[i].second;
    if(uf.find(ai) != uf.find(bi)){
      int mainax = uf.gsize(ai) * uf.gsize(bi);
      ans[i-1] = ans[i] - mainax;
      uf.unite(ai,bi);
    }else{
      ans[i-1] = ans[i];
    }
  }
  for(int i=0; i<m; ++i) cout << ans[i] << endl;
}