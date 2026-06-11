#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;

template<typename T,bool directed>
struct Fordfulkerson{
  struct edge{
    ll to,cap,rev;
    edge(){}
    edge(ll to,ll cap,ll rev):to(to),cap(cap),rev(rev){}
  };

  vector<vector<edge> > G;
  vector<ll> used;

  Fordfulkerson(){}
  Fordfulkerson(ll n):G(n),used(n){}

  void add_edge(ll from,ll to,T cap){
    G[from].emplace_back(to,cap,G[to].size());
    G[to].emplace_back(from,directed?0:cap,G[from].size()-1);
  }

  T dfs(ll v,ll t,T f){
    if(v==t) return f;
    used[v]=true;
    for(ll i=0;i<(ll)G[v].size();i++){
      edge &e = G[v][i];
      if(!used[e.to]&&e.cap>0){
        T d=dfs(e.to,t,min(f,e.cap));
        if(d>0){
          e.cap-=d;
          G[e.to][e.rev].cap+=d;
          return d;
        }
      }
    }
    return 0;
  }

  ll flow(ll s,ll t,T lim){
    T fl=0;
    while(1){
      fill(used.begin(),used.end(),0);
      T f=dfs(s,t,lim);
      if(f==0) break;
      fl+=f;
      lim-=f;
    }
    return fl;
  }

  ll flow(ll s,ll t){
    return flow(s,t,numeric_limits<T>::max()/2);
  }

};

int main() {
  ll n;
  cin >> n;
  vec x(2*n),y(2*n);
  Fordfulkerson<ll,true> G(2*n+2);
  for(ll i=0;i<n;i++) {
    cin >> x[i] >> y[i];
    G.add_edge(2*n,i,1);
  }
  for(ll i=0;i<n;i++) {
    cin >> x[n+i] >> y[n+i];
    G.add_edge(n+i,2*n+1,1);
  }
  for(ll i=0;i<n;i++) {
    for(ll j=0;j<n;j++) {
      if(x[i]<x[n+j]&&y[i]<y[n+j]) {
        G.add_edge(i,n+j,1);
      }
    }
  }
  cout << G.flow(2*n,2*n+1) << endl;
}