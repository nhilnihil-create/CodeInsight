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
#define SIZE(a) int((a).size();
const int INF=1e9;

int main(){
  ll n,k;cin>>n>>k;
  vll x(n);
  rep(i,0,n){
    cin>>x[i];
  }
  ll ans=INF;
  rep(i,0,n-k+1){
    if(x[i+k-1]<0){
      ans=min(ans,-x[i]);
    }
    else{
      if(x[i]<0){
        ans=min(ans,min(x[i+k-1]-2*x[i],x[i+k-1]*2-x[i]));
      }
      else{ans=min(ans,x[i+k-1]);}
    }
  }
  cout<<ans<<endl;
}
