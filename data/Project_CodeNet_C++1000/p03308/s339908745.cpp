#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i<(n); ++i)

int main() {
  ll n; cin >> n;
  vector<ll>v(n);
  ll a,b;
  rep(i,n){
    cin >> v.at(i);
  }
  sort(v.begin(),v.end());
  cout << abs(v.at(n-1)-v.at(0)) << endl;
  
  
  return 0;
}