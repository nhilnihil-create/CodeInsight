#include <bits/stdc++.h>

using namespace std;

int main(){
  using ll = int64_t;
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n), b(n);
  for(int i=0;i<n;i++){
    cin >> a[i] >> b[i]; 
  }
  ll ans = 0;
  for(int j=0;j<n;j++){
    if((k | a[j]) == k)ans += b[j]; 
  }
  for(int i=1;i<31;i++){
    if((k & (1LL << i)) == 0)continue;
    ll x = ((k >> i) << i) - 1;
    ll t = 0LL;
    for(int j=0;j<n;j++){
      if((x | a[j]) == x)t += b[j]; 
    }
    ans = max(ans, t);
    // cerr << i << " " << t << " " << ans << endl;
  }
  cout << ans << endl;
}
