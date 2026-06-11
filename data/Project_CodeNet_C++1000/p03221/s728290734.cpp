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
string tstring(ll n){
  string t=to_string(n);
  while(t.size()<6){
    t="0"+t;
  }
  return t;
}
int main(){
  ll n,m;cin>>n>>m;
  vector<vp> s(n);vll pp(m);
  vector<string> ans(m);
  rep(i,0,m){
    ll y,p;cin>>p>>y;
    s[p-1].push_back(make_pair(y,i));
    pp[i]=p;
  }
  rep(i,0,n)sort(s[i].begin(),s[i].end());
  for(auto u:s){
    rep(i,0,u.size()){
      
      ans[u[i].second]=tstring(pp[u[i].second])+tstring(i+1);
      
    }
  }
  rep(i,0,m){
    cout<<ans[i]<<endl;
  }
}






