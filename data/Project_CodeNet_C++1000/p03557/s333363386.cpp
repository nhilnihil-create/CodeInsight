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
#define SIZE(a) int((a).size())
#define out(a) cout<<(a)<<endl;
const int INF=INT_MAX;
const int MAX = 510000;
const ll MOD = 1000000007;

int main(){
  ll n,ans;cin>>n;
  vll a(n),b(n),c(n);
  rep(i,0,n){
    cin>>a[i];
  }
  rep(i,0,n){
    cin>>b[i];
  }
  rep(i,0,n){
    cin>>c[i];
  }
  sort(a.begin(),a.end());sort(c.begin(),c.end());
  rep(i,0,n){
    auto it=lower_bound(a.begin(),a.end(),b[i]);
    ll tmp=it-a.begin();
    auto it2=upper_bound(c.begin(),c.end(),b[i]);
    ans+=tmp*(c.end()-it2);
  }
  out(ans);
}
