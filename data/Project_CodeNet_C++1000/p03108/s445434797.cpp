#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

class UnionFind {
public:
  vector<ll> par, siz;
  UnionFind(ll sz_) : par(sz_), siz(sz_, 1) {
    for(int i=0; i<sz_; ++i) par[i]=i;
  }
  void init(ll sz_) {
    par.resize(sz_);
    siz.assign(sz_,1);
    for(int i=0; i<sz_; ++i) par[i]=i;
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
  ll N, M; cin>>N>>M;
  vector<pair<ll, ll>> bridges(M);
  vector<ll> ans(M);
  UnionFind islands(N);
  for(int i=0; i<M; ++i) {
    ll x, y; cin>>x>>y; x--; y--;
    bridges[i].first=x; bridges[i].second=y;
  }
  ll inconvenience = N*(N-1)/2;
  for(int i=M-1; i>=0; --i) {
    ll x = bridges[i].first;
    ll y = bridges[i].second;

    ans[i]=inconvenience;

    if(!islands.issame(x,y)) {
      inconvenience+=islands.size(x)*(islands.size(x)-1)/2;
      inconvenience+=islands.size(y)*(islands.size(y)-1)/2;
      islands.merge(x, y);
      inconvenience-=islands.size(x)*(islands.size(x)-1)/2;
    } else {
      islands.merge(x, y);
    }
  }
  for(auto v:ans) cout<<v<<endl;
}
