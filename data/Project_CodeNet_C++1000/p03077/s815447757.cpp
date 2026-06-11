#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll n;
  vector<ll> a(5);
  cin >> n >> a[0] >> a[1] >> a[2] >> a[3] >> a[4]; 
  ll m = n;
  ll ans = 4;
  rep(i,5){
    if(m > a[i])
      m = a[i];
  }
  ans += (n + m - 1) / m;
  
  cout << ans << endl;
}