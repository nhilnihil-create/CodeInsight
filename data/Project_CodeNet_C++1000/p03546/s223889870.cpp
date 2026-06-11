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
#define SIZE(a) int((a).size())
#define out(a) cout<<(a)<<endl;
const int INF=INT_MAX;
const int MAX = 510000;
const ll MOD = 1L<<32;
ll fac[MAX], finv[MAX], inv[MAX];
//ワーシャルフロイド法、o(v^3)
int main(){
  ll v,e,ans=0;cin>>v>>e;
  ll g[10][10];
  rep(i,0,10){
    rep(j,0,10){
      cin>>g[i][j];
    }
  }
  bool ok=true;
  rep(k,0,10){
    rep(i,0,10){
      if(g[i][k]==MOD)continue;
      rep(j,0,10){
        if(g[k][j]==MOD)continue;
        g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
      }
      if(g[i][i]<0)ok=false;//負の閉回路の検出
    }
  }
  rep(i,0,v){
    rep(j,0,e){
      ll a;
      cin>>a;
      if(a==-1)continue;
      ans+=g[a][1];
    }
  }
  out(ans);
  
}


