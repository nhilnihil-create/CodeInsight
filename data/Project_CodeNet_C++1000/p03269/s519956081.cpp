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
      ans=ans*x;
    }
    x=x*x;
    n>>=1;
  }
  return ans;
}

int main() {
  ll l;
  cin >> l;
  ll n=2;
  while(mpow(2,n)-1<l) {
    n++;
  }
  vec a,b,c;
  for(ll i=1;i<n;i++) {
    a.push_back(i);
    b.push_back(i+1);
    c.push_back(0);
    a.push_back(i);
    b.push_back(i+1);
    c.push_back(mpow(2,i-1));
  }
  ll cnt=l-mpow(2,n-1);
  for(ll i=n-1;i&&l;i--) {
    if(cnt>=mpow(2,i-1)) {
      ll tmp=l-mpow(2,i-1);
      a.push_back(i);
      b.push_back(n);
      c.push_back(tmp);
      l-=mpow(2,i-1);
      cnt-=mpow(2,i-1);
    }
  }
  ll m=a.size();
  cout << n << " " << m << endl;
  for(ll i=0;i<m;i++) {
    cout << a[i] << " " << b[i] << " " << c[i] << endl;
  }
}