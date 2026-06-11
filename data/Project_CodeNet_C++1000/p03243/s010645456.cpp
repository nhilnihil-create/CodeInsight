#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n; cin >> n;
  ll ans;
  for(ll i = n; i<(n+111); i++){
    if(i%111==0) ans+=i;
  }
  cout << ans << endl;
  
  return 0;
}