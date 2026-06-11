#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

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
    ll f,e,l,a;
    cin >> f >> e >> l >> a;
    ll flag=1;
    if(f<e) flag=0;
    if(a<e) flag=0;
    if(flag&&l<e) {
      ll g=gcd(e,a);
      if(e-g+(f%g)>l) {
        flag=0;
      }
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}