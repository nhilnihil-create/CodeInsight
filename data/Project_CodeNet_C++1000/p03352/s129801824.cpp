#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define drep(i,a,b) for(ll i=(a);i>=(b);--i)
#define SIZE(a) int((a).size())
const int INF=INT_MAX;


int main(){
  ll n,ans=1;cin>>n;
  for(int i=2;i*i<=n;i++){
    ll tmp=i;
    while(tmp<=n/i){
      tmp*=i;
    }
    ans=max(ans,tmp);
  }
  cout<<ans<<endl;
}