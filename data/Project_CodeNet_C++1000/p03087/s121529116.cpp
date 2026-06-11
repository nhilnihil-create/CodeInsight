#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD =1000000007;

ll modPow(ll a, ll n) {
  if (n == 0) return 1; // 0乗にも対応する場合
  if (n == 1) return a % MOD;
  if (n % 2 == 1) return (a * modPow(a, n - 1)) % MOD;
  ll t = modPow(a, n / 2);
  return (t * t) % MOD;
}
ll modComb(ll n,ll a){
  ll x=1,y=1;
  rep(i,a){
    x*=n-i;
    x%=MOD;
    y*=i+1;
    y%=MOD;
  }
  y=modPow(y,MOD-2);
  return (x*y)%MOD;
}

int main(){
  ll N,Q;
  string S;
  cin >> N >> Q >> S;
  vector<ll> dp(N+1,0);
  dp.at(0)=0;
  for(ll i=1;i<N;i++){
    if(S.at(i-1)=='A'&&S.at(i)=='C'){
      dp.at(i+1)=dp.at(i)+1;
    }else{
      dp.at(i+1)=dp.at(i);
    }
  }
  rep(i,Q){
    ll l,r;
    cin >> l >> r;
    cout << dp.at(r)-dp.at(l) << endl;
  }
}
