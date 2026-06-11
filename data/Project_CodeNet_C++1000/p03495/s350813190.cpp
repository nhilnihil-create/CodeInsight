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
  ll n,k;cin>>n>>k;
  vll c(n+1);
  rep(i,0,n){
    ll a;cin>>a;
    c[a]++;
  }
  ll ans=0;
  sort(c.begin(),c.end());
  rep(i,0,n-k+1){
    ans+=c[i];
  }
  cout<<ans<<endl;
}





