#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef pair<ll,ll> P;
typedef vector<P> vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define drep(i,a,b) for(ll i=(a);i>=(b);--i)
#define SIZE(a) ll((a).size())
#define out(a) cout<<(a)<<endl;
const int inf=INT_MAX;
const int MAX = 510000;
const ll MOD = 1000000007;


vll par(MAX),siz(MAX);

//par[i]=iならiは根（はじめは全て根）
void init(ll n){
  rep(i,0,n){
    par[i]=i;siz[i]=1LL;
  }
  return;
}
//xの根
ll root(ll x){
  return (par[x]==x)?x:par[x]=root(par[x]);
}
//xが根の木とyが根の木を繋げる
void unite(ll x,ll y){
  x=root(x);y=root(y);
  if(x==y){return;}
  if(siz[x]<siz[y]){swap(x,y);}
  siz[x]+=siz[y];
  par[y]=x;
}
//根が同じかどうか
bool same(ll x,ll y){
  return root(x)==root(y);
}
int main(){
  ll n,m;cin>>n>>m;
  init(n);
  vp g(m);
  rep(i,0,m){
    cin>>g[i].first>>g[i].second;
    g[i].first--;g[i].second--;
  }
  vll ans(m);
  ans[m-1]=(n*(n-1))/2;
  set<ll>s;
  
  drep(i,m-1,1){
    if(root(g[i].first)!=root(g[i].second)){
      ans[i-1]=ans[i]-siz[root(g[i].first)]*siz[root(g[i].second)];
    }
    else ans[i-1]=ans[i];
    unite(g[i].first,g[i].second);
    
  }
  rep(i,0,m)cout<<ans[i]<<endl;
  
}

