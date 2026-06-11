#include <bits/stdc++.h>

#define rep(i, n) for(int i=0; i < n; i++)
#define reps(i, n) for(int i=1; i <= n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()
#define rALL(v) v.rbegin(), v.rend() 
#define pb(x) push_back(x)

using namespace std;
using ll=long long;

long mod=1e9+7;

ll N,Q;

struct Unionfind{
  vector<ll> par,siz;
  //Constructor
  Unionfind(ll sz_):par(sz_),siz(sz_,1){
    for(ll i=0;i<sz_;i++)par[i]=i;
  }
  
  ll root(ll x){
    return par[x]==x?x:
    par[x]=root(par[x]);
  }

  bool same(ll x,ll y){
    return root(x)==root(y);
  }

  void unite(ll x,ll y){
    x=root(x);
    y=root(y);
    if(x==y)return;
    if(siz[x]<siz[y])swap(x,y);
    siz[x]+=siz[y];
    par[y]=x;
  }

  ll size(ll x){
    return siz[root(x)];
  }

};

int main() {
  ll n,a,b,c,d,e;
  cin>>n>>a>>b>>c>>d>>e;
  ll m=min(min(min(a,b),min(c,d)),e);
  ll ans=((n+m-1)/m)+4;
  cout<<ans;
}

