#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e18;
 
int main() {
  ll n;
  cin >> n;
  vec t(n),v(n);
  for(ll i=0;i<n;i++) cin >> t[i],t[i]*=2;
  for(ll i=0;i<n;i++) cin >> v[i],v[i]*=2;
  vec z(4e4+10);
  ll mv=0;
  ll ti=0;
  for(ll i=0;i<n;i++) {
    z[ti]=min(z[ti],v[i]);
    for(ll j=ti+1;j<=ti+t[i];j++) {
      z[j]=min(z[j-1]+1,v[i]);
    }
    ti+=t[i];
  }
  mv=0;
  double ans=0;
  for(ll i=ti-1;i;i--) {
    ans+=mv=min(mv+1,z[i]);
  }
  ans*=1/4.0;
  cout << fixed << setprecision(10) << ans << endl;
}