#include <iostream>
#include <vector>
#include <cmath>
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
using namespace std;

int main(){
  ll n;
  cin >> n;
  vector<ll> a(5);
  ll x = 1000000000000000;
  rep(i, 5){
    cin >> a[i];
    x = min(x, a[i]);
  }
  ll ans = (n-1) / x + 5;
  cout << ans << endl;
  
  return 0;
}