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
  string s;cin>>s;
  ll w=0,b=0,ans=MOD,lb=0,lw=0;
  rep(i,0,n){
    if(s[i]=='#')b++;
    else w++;
  }
  ans=w;
  rep(i,0,n){
    if(s[i]=='#'){
      lb++;
      
    }
    else lw++;
    ans=min(ans,lb+w-lw);
  }
  cout<<ans<<endl;
}

