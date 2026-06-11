#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n, x;
  cin >> n;
  map<ll, int> mp;
  ll rui = 0;
  ll ans = 0;
  for(int i=0; i<n; ++i){
    cin >> x;
    rui += x;
    ans += mp[rui];
    ++mp[rui];
  }
  ans += mp[0];
  cout << ans << endl;
}