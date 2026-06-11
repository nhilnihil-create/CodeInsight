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
  vec a(n);
  vec b(n);
  for(ll i=0;i<n;i++) cin >> a[i];
  for(ll i=0;i<n;i++) cin >> b[i];
  for(ll i=0;i<n-1;i++) a[i+1]+=a[i];
  for(ll i=n-1;i;i--) b[i-1]+=b[i];
  ll ans=0;
  for(ll i=0;i<n;i++) {
    ans=max(ans,a[i]+b[i]);
  }
  cout << ans << endl;
}