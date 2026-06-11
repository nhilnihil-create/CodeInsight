#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

int main() {
  ll n;
  cin >> n;
  vec x(n),y(n),h(n);
  for(ll i=0;i<n;i++) {
    cin >> x[i] >> y[i] >> h[i];
  }
  for(ll tx=0;tx<=100;tx++) {
    for(ll ty=0;ty<=100;ty++) {
      ll th=inf;
      for(ll i=0;i<n;i++) {
        th=min(th,abs(tx-x[i])+abs(ty-y[i])+h[i]);
      }
      ll f=1;
      for(ll i=0;i<n;i++) {
        ll tth=max(th-abs(tx-x[i])-abs(ty-y[i]),0LL);
        if(tth!=h[i])f=0;
      }
      if(f) {
        cout << tx << " " <<  ty << " " << th << endl;
        return 0;
      }
    }
  }
}