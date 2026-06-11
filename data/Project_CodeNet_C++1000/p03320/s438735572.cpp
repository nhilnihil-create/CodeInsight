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

ll sum(ll k) {
  ll res=0;
  while(k) {
    res+=k%10;
    k/=10;
  }
  return res;
}

ll nine(ll k) {
  ll res=0;
  ll tmp=1;
  while(k-->0) {
    res+=tmp*9;
    tmp*=10;
  }
  return res;
}

int main() {
  ll k;
  cin >> k;
  ll tmp=10;
  ll pre=0;
  ll cnt=1;
  while(k--) {
    pre++;
    while(pre/tmp) {
      tmp*=10;
      cnt++;
    }
    double v=-1.0;
    ll x=pre;
    for(ll i=0;i<cnt;i++) {
      ll id=pre/mpow(10,i+1)*mpow(10,i+1)+nine(i);
      for(ll j=0;j<=9;j++) {
        ll tid=id+j*mpow(10,i);
        if(tid<pre) continue;
        double tv=double(tid)/sum(tid);
        if(v<0.0||tv<v) {
          v=tv;
          x=tid;
        }
      }
    }
    cout << x << endl;
    pre=x;
  }
}