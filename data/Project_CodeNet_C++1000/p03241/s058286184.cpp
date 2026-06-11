#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

vector<ll> divisor(ll n) {
  vector<ll> res;
  for(ll i=1;i*i<=n;i++) {
    if(n%i==0) {
      res.push_back(i);
      if(i!=n/i) {
        res.push_back(n/i);
      }
    }
  }
  return res;
}

int main() {
  ll n,m;
  cin >> n >> m;
  vec div=divisor(m);
  ll ans=1;
  for(ll t:div) {
    if(t*n<=m) ans=max(ans,t);
  }
  cout << ans << endl;
}