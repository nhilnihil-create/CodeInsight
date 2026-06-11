#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef vector<pair<ll,ll> > vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define MOD 1000000007;

int main(){
  ll n,m,ans=0;cin>>n>>m;
  vll x(n),y(n),z(n);
  rep(i,0,n){
    cin>>x[i]>>y[i]>>z[i];
  }
  rep(i,0,1<<3){
    vll all(n,0);ll tmp=0;
    rep(j,0,n){
      if(i>>2&1){all[j]+=x[j];}
      else{all[j]-=x[j];}
      if(i>>1&1){all[j]+=y[j];}
      else{all[j]-=y[j];}
      if(i>>0&1){all[j]+=z[j];}
      else{all[j]-=z[j];}
    }
    sort(all.begin(),all.end());
    reverse(all.begin(),all.end());
    rep(j,0,m){
      tmp+=all[j];
    }
    ans=max(ans,tmp);
  }
  cout<<ans<<endl;
}

