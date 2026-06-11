#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
using namespace std;
using P = pair<ll, ll>;

int main(){
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  vector<P> bc(m);
  rep(i, n) cin >> a[i];
  rep(i, m){
    ll b, c;
    cin >> b >> c;
    bc[i] = P(c, b);
  }
  sort(a.rbegin(), a.rend());
  sort(bc.rbegin(), bc.rend());
  ll ans = 0;
  ll x = 0, y = 0, z = 0;
  rep(i, n){
    if (a[x] > bc[y].first){
      ans += a[x];
      x++;
    }
    else{
      ans += bc[y].first;
      z++;
      if (z == bc[y].second){
        z = 0;
        y++;
      }
    }
  }
  cout << ans << endl;
  
  return 0;
}