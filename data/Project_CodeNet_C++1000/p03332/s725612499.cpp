#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
//const ll mod=1e9+7;
const ll mod=998244353;
const ll inf=5e18;

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

//階乗,factで初期化
vector<ll> tfact(1e7+1);
void fact(ll n) {
  for(ll i=0;i<=n;i++) {
    if(i==0) {
      tfact[i]=1;
    }
    else {
      tfact[i]=tfact[i-1]*i%mod;
    }
  }
}

//nCk 繰り返し高速
ll comb(ll n, ll k) {
  return tfact.at(n)*mpow(tfact.at(k),mod-2)%mod*mpow(tfact.at(n-k),mod-2)%mod;
}

int main() {
  ll n,k,a,b;
  cin >> n >> a >> b >> k;
  fact(n);
  ll ans=0;
  for(ll i=0;i<=n;i++) {
    ll j=(k-i*a);
    if(j%b==0&&j>=0&&j/b<=n) {
      j/=b;
      ans=(ans+comb(n,i)*comb(n,j)%mod)%mod;
    }
  }
  cout << ans << endl;
}