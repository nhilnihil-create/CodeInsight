#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(ll i = (s); i < (n); i++)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(18);
  
  ll n;
  cin >> n;
  vector<ll> a(n+2);
  a[0] = 0;
  rep(i, 1, n+1) cin >> a[i];
  a[n+1] = 0;
  
  ll sum = 0;
  rep(i, 0, n+2-1) sum += abs(a[i+1]-a[i]);
  
  rep(i, 1, n+1) {
    ll diff = abs(a[i-1]-a[i])+abs(a[i]-a[i+1]) - abs(a[i+1]-a[i-1]);
    cout << sum-diff << "\n";
  }
}