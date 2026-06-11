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
  ll n,m;
  cin >> n >> m;
  vec x(n);
  vec y(n);
  vec z(n);
  for(ll i=0;i<n;i++) {
    cin >> x[i] >> y[i] >> z[i];
  }
  vec modx={1,1,1,1,-1,-1,-1,-1};
  vec mody={1,-1,1,-1,1,-1,1,-1};
  vec modz={1,1,-1,-1,1,1,-1,-1};
  ll ans=0;
  for(ll i=0;i<8;i++) {
    ll tans=0;
    vec p(n);
    for(ll j=0;j<n;j++) {
      p[j]=modx[i]*x[j]+mody[i]*y[j]+modz[i]*z[j];
    }
    sort(p.rbegin(),p.rend());
    for(ll j=0;j<m;j++) {
      tans+=p[j];
    }
    ans=max(ans,tans);
  }
  cout << ans << endl;
}