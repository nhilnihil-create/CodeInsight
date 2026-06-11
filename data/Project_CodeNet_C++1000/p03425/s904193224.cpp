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
  vll m(5,0);
  rep(i,0,n){
    string s;cin>>s;
    if(s[0]=='M')m[0]++;
    if(s[0]=='R')m[1]++;
    if(s[0]=='A')m[2]++;
    if(s[0]=='C')m[3]++;
    if(s[0]=='H')m[4]++;
  }
  sort(m.begin(),m.end());
  ll cnt=0,ans=0;
  rep(i,0,5){
    if(m[i]==0){
      cnt++;
    }
  }
  if(cnt>=3){
    cout<<0<<endl;
  }
  else{
    rep(i,0,5){
      rep(j,0,i){
        rep(k,0,j){
          ans+=m[i]*m[j]*m[k];
        }
      }
      
    }
    cout<<ans<<endl;
  }
  
}





