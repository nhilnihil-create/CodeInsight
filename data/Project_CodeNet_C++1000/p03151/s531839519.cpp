#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)

int main(){
  ll n;cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a.at(i);
  vector<ll> b(n);
  rep(i,n) cin >> b.at(i);

  vector<ll> num;
  ll amari = 0;
  ll tarinai_cnt = 0;
  ll tarinai_sum = 0;
  rep(i,n){
    ll c = a.at(i) - b.at(i);
    if( c > 0 ){
      num.push_back(c);
      amari += c;
    }else if( c < 0 ){
      tarinai_cnt++;
      tarinai_sum -= c;
    }
  }
  if( amari < tarinai_sum ){
    cout << -1 << endl;
    return 0;
  }
  if( tarinai_cnt == 0 ){
    cout << 0 << endl;
    return 0;
  }
  sort(num.begin(),num.end());
  ll ans = tarinai_cnt;
  ll sum = 0;
  for(ll i=num.size()-1;i>=0;--i){
    sum += num.at(i);
    ++ans;
    if( sum > tarinai_sum ){
      cout << ans << endl;
      return 0;
    }
  }

  return 0;
}
