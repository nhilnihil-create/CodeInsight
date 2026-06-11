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


int main(){
  ll n;cin>>n;
  vll d(13,0);
  rep(i,0,n){
    ll t;cin>>t;
    d[t]++;
  }
  rep(i,0,13){
    if(d[i]>=3||d[12]>=2||d[0]>0){
      cout<<0<<endl;return 0;
    }
  }
  ll ans=0;
  rep(i,0,1<<11){
    vll tmp(25,0);
    tmp[24]++;
    if(d[12])tmp[12]++;
    rep(j,0,11){
      if(d[j+1]==0)continue;
      if(d[j+1]>1){
        tmp[j+1]++;tmp[24-j-1]++;
      }
      if(d[j+1]==1){
        if(i>>j&1)tmp[j+1]++;
        else tmp[24-j-1]++;
      }
    }
    ll cnt=24,now=0;
    rep(j,0,25){
      if(tmp[j]){
        cnt=min(cnt,j-now);
        now=j;
      }
    }
    ans=max(ans,cnt);
  }
  cout<<ans<<endl;
}

