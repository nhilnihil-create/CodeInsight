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
  ll l;
  cin >> l;
  ll n=0;
  while(mpow(2,n)<=l) n++;
  vec a,b,c;
  ll sum=0;
  for(ll i=1;i<n;i++) {
    a.push_back(i);
    b.push_back(i+1);
    c.push_back(0);
    a.push_back(i);
    b.push_back(i+1);
    c.push_back(mpow(2,i-1));
  }

  for(ll i=n-1;i;i--) {
    if(l-mpow(2,i-1)>=mpow(2,n-1)) {
      a.push_back(i);
      b.push_back(n);
      c.push_back(l-mpow(2,i-1));
      l-=mpow(2,i-1);
    }
  }
  cout << n << " " << a.size() << endl;
  for(ll i=0;i<a.size();i++) {
    cout << a[i] << " " << b[i] << " " << c[i] << endl;
  }
}