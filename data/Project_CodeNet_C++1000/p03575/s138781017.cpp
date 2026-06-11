#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

class UnionFind {
public:
  vector<ll> par,siz;
  UnionFind(ll sz_) : par(sz_), siz(sz_,1) {
    for(int i=0; i<sz_; ++i) par[i]=i;
  }
  void init(ll sz_) {
    par.resize(sz_);
    siz.assign(sz_,1);
    for(ll i=0; i<sz_; ++i) par[i]=i;
  }

  ll root(ll x) {
    while(x!=par[x]) {
      x = par[x] = par[par[x]];
    }
    return x;
  }

  void merge(ll x, ll y) {
    x = root(x);
    y = root(y);
    if(x!=y) {
      if(siz[x]<siz[y]) swap(x,y);
      siz[x]+=siz[y];
      par[y]=x;
    }
  }

  bool issame(ll x, ll y) {
    return root(x) == root(y);
  }

  ll size(ll x) {
    return siz[root(x)];
  }
};

int main() {
  int N, M; cin >> N >> M;
  vector<pair<ll, ll>> edges(M);
  UnionFind graph(N);
  for(int i=0; i<M; ++i) {
    ll a,b; cin>>a>>b;
    a--; b--;
    edges[i] = {a,b};
  }
  int cnt=0;
  for(int i=0; i<M; i++) {
    graph.init(N);
    for(int j=0; j<M; j++) {
      if(i==j) continue;
      graph.merge(edges[j].first, edges[j].second);
    }
    if(graph.size(0)!=N) cnt++;
  }
  cout << cnt << endl;
}
