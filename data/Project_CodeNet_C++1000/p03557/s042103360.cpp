#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < n; i++)
using namespace std;

ll binary_search(ll val, vector<ll> &v){
  ll left = -1, right = v.size();
  while(right - left > 1){
    ll mid = left + (right - left) / 2;
    if ( v[mid] >= val ) right = mid;
    else left = mid;
  }
  return right;
}

int main(){
  ll n;
  cin >> n;
  vector<ll> a(n), b(n), c(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  rep(i, n) cin >> c[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());
  
  ll ans = 0;
  rep(i, n){
    ll top = binary_search(b[i], a);
    ll under = n - binary_search(b[i]+1, c);
    ans += top * under;
  }
  cout << ans << endl;
  
  return 0;
}