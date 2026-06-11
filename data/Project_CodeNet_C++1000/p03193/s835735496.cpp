#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
  ll n,h,w;
  cin >> n >> h >> w;
  ll ans=0;
  for(ll i=0;i<n;i++) {
    ll x,y;
    cin >> x >> y;
    if(x>=h&&y>=w) {
      ans++;
    }
  }
  cout << ans << endl;
}