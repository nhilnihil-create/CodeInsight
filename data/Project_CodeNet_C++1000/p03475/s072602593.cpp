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

int main(){
  ll n;cin>>n;
  vll c(n-1),s(n-1),f(n-1);
  rep(i,0,n-1){
    cin>>c[i]>>s[i]>>f[i];
  }
  rep(i,0,n-1){
    ll now=s[i];
    rep(j,i,n-1){
      ll tmp=(now-s[j])/f[j];
      if(now-s[j]<0){
        now=s[j]+c[j];
      }
      else if((now-s[j])%f[j]==0){
        now=s[j]+f[j]*tmp+c[j];
      }
      else now=s[j]+f[j]*(tmp+1)+c[j];
      
    }
    cout<<now<<endl;
  }
  cout<<0<<endl;
}

