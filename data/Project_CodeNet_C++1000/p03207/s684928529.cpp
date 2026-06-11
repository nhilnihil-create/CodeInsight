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
  vec p(n);
  for(ll i=0;i<n;i++) cin >> p[i];
  sort(p.rbegin(),p.rend());
  ll ans=-p[0]/2;
  for(ll i=0;i<n;i++) {
    ans+=p[i];
  }
  cout << ans << endl;
}