#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll a, b;
  cin >> a >> b;
  --a;
  ll ans = 0;
  for(ll i=(a/4)*4; i<=a; ++i){
    ans ^= i;
  }
  for(ll i=(b/4)*4; i<=b; ++i){
    ans ^= i;
  }
  cout << ans << endl;
}