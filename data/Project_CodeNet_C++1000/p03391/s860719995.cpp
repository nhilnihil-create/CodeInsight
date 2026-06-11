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
  vec a(n),b(n);
  for(ll i=0;i<n;i++) cin >> a[i] >> b[i];
  ll mi=inf;
  ll ans=0;
  for(ll i=0;i<n;i++) {
    if(a[i]>b[i]) {
      mi=min(mi,b[i]);
    }
    ans+=a[i];
  }
  ans-=mi;
  if(mi==inf) ans=0;
  cout << ans << endl;
}