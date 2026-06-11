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
  vll a(n);
  vector<set<ll> > vs(n);
  rep(i,0,n){
    cin>>a[i];
    rep(j,0,20){
      if(a[i]>>j&1){
        vs[i].insert(j);
      }
    }
  }
  
  ll ans=0;
  set<ll> tmp;ll now=0;
  rep(i,0,n){
    bool ok=false;
    while(now<n){
      for(auto u:vs[now]){
        if(tmp.count(u)){
          ok=true;
        }
      }
      if(ok)break;
      if(!ok){
        for(auto u:vs[now]){
          tmp.insert(u);
        }
      }

      now++;
    }
    
    ans+=now-i;
    
    for(auto u:vs[i]){
      tmp.erase(u);
    }
  }
  cout<<ans<<endl;

}


