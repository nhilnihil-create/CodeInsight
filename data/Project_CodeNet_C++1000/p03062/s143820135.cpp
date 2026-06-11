#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)


int main() {
  ll n;cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a.at(i);

  // rep(i,2){
  //   for(ll i=0;i<n-1;++i){
  //     ll sum = a.at(i) + a.at(i+1);
  //     if( sum < 0 ){
  //       a.at(i) *= -1;
  //       a.at(i+1) *= -1;
  //     }
  //   }
  // }
  // ll ans = 0;
  // rep(i,n) ans += a.at(i);

  sort(a.begin(),a.end());

  ll cnt = 0;
  rep(i,n){
    if( a.at(i) < 0 ) ++cnt;
  }

  ll ans = 0;
  rep(i,n) ans += abs(a.at(i));

  if( cnt%2 != 0 ){
    ll m = 9999999999;
    rep(i,n) m = min(m,abs(a.at(i)));
    ans -= m*2;
  }


  cout << ans << endl;
  
  return 0;
}