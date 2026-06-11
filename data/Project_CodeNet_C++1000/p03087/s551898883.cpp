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
  ll n,q;cin>>n>>q;
  string s;cin>>s;
  vll sum(n,0);
  rep(i,0,n-1){
    if(s[i]=='A'&&s[i+1]=='C'){
      sum[i+1]=sum[i]+1;
    }
    else{sum[i+1]=sum[i];}
  }
  rep(i,0,q){
    ll l,r;cin>>l>>r;
    l--;r--;
    cout<<sum[r]-sum[l]<<endl;
  }

}


