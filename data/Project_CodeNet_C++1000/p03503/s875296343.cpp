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
const ll MOD = 1000000007;
ll fac[MAX], finv[MAX], inv[MAX];

int main(){
  ll n;cin>>n;
  
  vvll f(n,vll(10)),p(n,vll(11));

  
  rep(i,0,n){
    rep(j,0,10){
      cin>>f[i][j];
    }
  }
  rep(i,0,n){
    rep(j,0,11){
      cin>>p[i][j];
    }
  }
  ll ans=-MOD;
  rep(i,1,1<<10){
    vll mise(n,0);
    rep(j,0,10){
      if(i>>j&1){
        rep(k,0,n){
          if(f[k][j])mise[k]++;
        }
      }
    }
    ll tmp=0;
    rep(j,0,n){
      tmp+=p[j][mise[j]];
    }
    ans=max(ans,tmp);
  }
  cout<<ans<<endl;

}
