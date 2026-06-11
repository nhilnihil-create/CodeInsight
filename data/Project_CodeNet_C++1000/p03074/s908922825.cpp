#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
using namespace std;

int main(){
  ll n, k;
  string s;
  cin >> n >> k;
  cin >> s;
  vector<ll> sum;
  sum.push_back(0);
  char prev = s[0];
  rep(i, n){
    if (s[i] != prev){
      sum.push_back(i);
    }
    prev = s[i];
  }
  sum.push_back(n);
  sum.push_back(n);
  ll sz = sum.size();
  sum.push_back(n);
  ll x;
  if (s[0] == '0') x = 0;
  else x = 1;
  ll ans = 1;
  k = min(k, (sz-1)/2);
  for(ll i = x; i+k*2 <= sz; i+=2){
    if (i == 0) ans = max(ans, sum[k*2]);
    else ans = max(ans, sum[i+k*2]-sum[i-1]);
  }
  cout << ans << endl;
  
  return 0;
}