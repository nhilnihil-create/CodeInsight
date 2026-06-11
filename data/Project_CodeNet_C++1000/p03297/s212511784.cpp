#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e18;

ll gcd(ll a,ll b) {
  if(b==0) {
    return a;
  }
  else {
    return gcd(b,a%b);
  }
}

int main() {
  ll t;
  cin >> t;
  while(t--) {
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    if(b>a) {
      cout << "No" << endl;
      continue;
    }
    if(b<=a&&b>d) {
      cout << "No" << endl;
      continue;
    }
    if(b<=a&&d>=b&&c>=b) {
      cout << "Yes" << endl;
      continue;
    }
    ll g=gcd(b,d);
    if(b-g+a%g>c) cout << "No" << endl;
    else cout << "Yes" << endl;
  }
}