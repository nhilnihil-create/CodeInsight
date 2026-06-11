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
  ll n,k;
  ll x=0;
  cin >> n >> k;
  vec a(n);
  for(ll i=0;i<n;i++) cin >> a[i];
  ll ans=0;
  for(ll i=44;i>-1;i--) {
    ll cnt=0;
    for(ll j=0;j<n;j++) {
      if(a[j]&(1LL<<i)) cnt++;
    }
    if (cnt<n-cnt) {
      if(ans+(1LL<<i)<=k) ans+=(1LL<<i);
    }
  }
  ll sum=0;
  for(ll i=0;i<n;i++) sum+=ans^a[i];
  cout << sum << endl;
}