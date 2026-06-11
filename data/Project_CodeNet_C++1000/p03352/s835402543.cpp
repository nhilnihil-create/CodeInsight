#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

ll mpow(ll x, ll n) {
  ll ans=1;
  while(n>0) {
    if(n&1) {
      ans=ans*x%mod;
    }
    x=x*x%mod;
    n>>=1;
  }
  return ans;
}

int main() {
  ll x;
  cin >> x;
  vec ans;
  ans.push_back(1);
  for(ll i=2;mpow(i,2)<=x;i++) {
    for(ll j=2;mpow(i,j)<=x;j++) {
      ans.push_back(mpow(i,j));
    }
  }
  sort(ans.begin(),ans.end());
  cout << ans[ans.size()-1] << endl;
}