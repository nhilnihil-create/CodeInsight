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
  ll n,y;cin>>n>>y;
  bool ok=true;
  rep(i,0,n+1){
    rep(j,0,n-i+1){
      if(10000*i+5000*j+1000*(n-i-j)==y){
        ok=false;
        cout<<i<<" "<<j<<" "<<n-i-j<<endl;
        break;
      }
    }
    if(!ok){break;}
  }
  if(ok){
    cout<<-1<<" "<<-1<<" "<<-1<<endl;
  }
}





