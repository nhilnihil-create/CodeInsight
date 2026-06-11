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
  string s,t,ans="UNRESTORABLE";cin>>s>>t;
  rep(i,0,s.size()-t.size()+1){
    bool ok=true;
    rep(j,0,t.size()){
      if(s[i+j]=='?'||s[i+j]==t[j])continue;
      else{ok=false;}
    }
    if(ok){
      ans=s;
      rep(j,0,t.size()){
        ans[i+j]=t[j];
      }
      rep(j,0,ans.size()){
        if(ans[j]=='?')ans[j]='a';
      }
      
    }
    
  }
  cout<<ans<<endl;
}

