#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
カードは1か2
Zで偶数奇数がわかる
Unionかな
*/
vector<bool> seen;
vector<vector<ll>> G;
struct UnionFind{
  vector<ll> par,siz;
  
  UnionFind(ll N):par(N+1),siz(N+1,1){
    for(int i=0; i<=N; i++)
      par[i]=i;
  }
  
  void mkpar1(ll parent, ll n){//親は最上位
    for(auto next_n: G[n]){
      if(seen[next_n]) continue;
      seen[next_n]=true;
      par[next_n]=parent;
      mkpar1(parent, next_n);
    }
  }
  
  void mkpar2(ll n){//親は1個うえ
    for(auto next_n: G[n]){
      if(seen[next_n]) continue;
      seen[next_n]=true;
      par[next_n]=n;
      mkpar2(next_n);
    }
  }
  
  ll root(ll x){
    if(par[x]==x)
      return x;
    return par[x]=root(par[x]);
  }
  
  void unite(ll x, ll y){
    ll rx=root(x), ry=root(y);
    if(rx==ry)
      return;
    par[ry]=rx;
    siz[rx]+=siz[ry];    
  }
  
  bool issame(ll x, ll y){
    return root(x)==root(y);
  }
  
  ll size(ll x){
    return siz[root(x)];
  }
};
int main(){
  ll N,M; cin>>N>>M;
  seen.assign(N+1,false);
  G.assign(N+1, vector<ll>(0,0));
  for(ll i=0; i<M; i++){
    ll x,y,z; cin>>x>>y>>z;
    G[x].emplace_back(y);
    G[y].emplace_back(x);
  }
  UnionFind tree(N);
  for(ll i=1; i<=N; i++){
    seen[i]=true;
    tree.mkpar1(i,i);
  }
  set<ll> S;
  for(ll i=1; i<=N; i++) S.insert(tree.par[i]);
  cout<<S.size()<<endl;
}