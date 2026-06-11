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
  ll k;
  cin >> k;
  vec a(k);
  for(ll i=0;i<k;i++) {
    cin >> a[i];
  }
  ll mx=3;
  ll mn=2;
  if(a[k-1]!=2) {
    cout << -1 << endl;
    return 0;
  }
  for(ll i=1;i<k;i++) {
    ll team=a[k-1-i];
    if(mx<team) {
      cout << -1 << endl;
      return 0;
    }
    mx=mx/team*team+team-1;
    mn=(mn+team-1)/team*team;
    if(mn>mx) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << mn << " " << mx << endl;
}