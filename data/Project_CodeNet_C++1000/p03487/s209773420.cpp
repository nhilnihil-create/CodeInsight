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
  vll b(100001);
  ll ans=0;
  rep(i,0,n){
    ll a;cin>>a;
    if(a>100000){
      ans++;
    }
    else{
      b[a]++;
    }
  }
  rep(i,0,100001){
    if(b[i]>i){
      ans+=b[i]-i;
    }
    if(b[i]<i){
      ans+=b[i];
    }
  }
  cout<<ans<<endl;
}





