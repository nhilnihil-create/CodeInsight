#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll n; cin >> n;
  vector<ll> t(n+1); t[0] == 0;
  vector<P> p(n+1);
  p[0].first=0; p[0].second=0; 
  rep(i, n+1) cin >> t[i+1] >> p[i+1].first >> p[i+1].second;
  
  rep(i, n){
    ll dist = abs(p[i+1].first - p[i].first) + abs(p[i+1].second - p[i].second);
    if( dist > t[i+1]-t[i] || (dist-(t[i+1]-t[i]))%2 != 0 ){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}