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
  ll n,m;
  string s,t;
  cin >> n >> m >> s >> t;
  ll l=n*m/__gcd(n,m);
  for(ll i=0;i<n;i++) {
    if(i*m%n==0&&s[i]!=t[i*m/n]) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << l << endl;
}