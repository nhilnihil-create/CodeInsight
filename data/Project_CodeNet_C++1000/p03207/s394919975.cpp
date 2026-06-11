#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i<(n); ++i)

int main() {
  ll n; cin >> n;
  vector<ll>v(n);
  rep(i,n) cin >> v[i];
  sort(v.begin(),v.end());
  ll sum = 0;
  rep(i,n-1) sum+=v[i];
  sum+=v[n-1]/2;
  cout << sum << endl;
    
  return 0;
}