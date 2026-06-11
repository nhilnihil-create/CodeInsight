#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){
  ll n;
  cin >> n;
  vector<ll> ya;
  for(ll i = 1; i * i <= n; i++){
    if(n % i != 0) continue;
    ya.push_back(i);
    ll j = n / i;
    if(i == j) continue;
    ya.push_back(j);
  }

  ll ans = 0;
  for(ll add : ya){
    add--;
    if(add == 0) continue;
    if(n/add == n % add) ans += add;
  }
  cout << ans << endl;

  return 0;
}