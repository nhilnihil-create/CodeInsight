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
  ll h,w,d;
  cin >> h >> w >> d;
  vector<pll> n(h*w+10);
  for(ll y=1;y<=h;y++) {
    for(ll x=1;x<=w;x++) {
      ll tmp;
      cin >> tmp;
      n[tmp]=pll(y,x);
    }
  }
  vec p(h*w+10);
  for(ll i=1;i<=h*w-d;i++) {
    p[i+d]=p[i]+abs(n[i+d].first-n[i].first)+abs(n[i+d].second-n[i].second);
  }
  ll q;
  cin >> q;
  while(q--) {
    ll l,r;
    cin >> l >> r;
    ll ans=p[r]-p[l];
    cout << ans << endl;
  }
}