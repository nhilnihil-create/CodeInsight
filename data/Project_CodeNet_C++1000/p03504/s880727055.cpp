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
  ll n,k;cin>>n>>k;
  vll a(100001,0);
  vector<vp> g(k);
  rep(i,0,n){
    ll s,t,c;cin>>s>>t>>c;
    g[c-1].push_back(make_pair(s,t));
    
  }
  rep(i,0,k){
    if(g[i].size()==0)continue;
    sort(g[i].begin(),g[i].end());
    rep(j,0,g[i].size()-1){
      if(g[i][j].second==g[i][j+1].first){
        g[i][j+1].first=g[i][j].first;
      }
      else{
        a[g[i][j].first]++;a[g[i][j].second+1]--;
      }
    }
    a[g[i][g[i].size()-1].first]++;a[g[i][g[i].size()-1].second+1]--;
    
  }

  rep(i,1,100001){
    a[i]+=a[i-1];
  }
  ll ans=0;
  rep(i,0,100001){
    ans=max(ans,a[i]);
  }
  cout<<ans<<endl;
}

