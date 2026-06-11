#include "bits/stdc++.h"
using namespace std;
typedef int64_t ll;
typedef vector<int64_t> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef pair<ll,ll> P;
typedef vector<P> vp;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define SIZE(a) int((a).size())
const int inf=100000;

vll par(inf),myrank(inf);
//par[i]=iならiは根（はじめは全て根）
void init(ll n){
  REP(i,n){
    par[i]=i;myrank[i]=0;
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
  if(myrank[x]<myrank[y]){par[x]=y;}
  else{par[y]=x;}
  if(myrank[x]==myrank[y]){myrank[x]++;}
}
//根が同じかどうか
bool same(ll x,ll y){
  return root(x)==root(y);
}


int main(){
  ll n,q,ans=0;
  cin>>n>>q;
  vvll e(q,vll(2));
  init(n);
  REP(i,q){
    cin>>e[i][0]>>e[i][1];
    e[i][0]--;e[i][1]--;
  }
  REP(i,q){
    init(n);
    REP(j,q){
      if(i!=j&&!same(e[j][0],e[j][1])){
        unite(e[j][0],e[j][1]);
      }
    }
    ll cnt=0;
    REP(j,n){
      if(par[j]==j)cnt++;
    }
    if(cnt>1)ans++;
  }
  cout<<ans<<endl;
}
