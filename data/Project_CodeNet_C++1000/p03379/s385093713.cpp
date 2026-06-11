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
  vp h(n);
  rep(i,0,n){
    cin>>h[i].first;
    h[i].second=i;
  }
  sort(h.begin(),h.end());
  vp x(n);
  rep(i,0,n){
    x[h[i].second]=make_pair(h[i].first,i);
  }
  rep(i,0,n){
    if(x[i].second+1<=n/2){
      cout<<h[n/2].first<<endl;
    }
    else{
      cout<<h[n/2-1].first<<endl;
    }
  }
}






