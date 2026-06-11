#include <iostream>
#include <vector>
#include <cmath>
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
using namespace std;

int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  ll count = 0;
  ll ma = 1000000000;
  ll sum = 0;
  rep(i, n){
    cin >> a[i];
    if (a[i] < 0) count++;
    ma = min(ma, abs(a[i]));
    sum += abs(a[i]);
  }
  if (count % 2 == 0) cout << sum << endl;
  else cout << sum - ma*2 << endl;
  
  return 0;
}