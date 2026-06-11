#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
ll gcd(ll a, ll b){
  ll r=a%b;
  while(r>0){
    a = b;
    b = r;
    r = a%b;
  }
  return b;
}
int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  
  ll ans = a[0];
  for(ll i=1;i<n;i++){
    ans = gcd(ans,a[i]);
    //cout << ans << endl;
  }
  
  cout << ans << endl;
  
  return(0);
}
