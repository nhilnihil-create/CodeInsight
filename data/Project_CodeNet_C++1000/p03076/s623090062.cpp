#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  ll ans = 0, hmin=100;
  rep(i,5){
    ll x = 0;
    cin >> x;
    if(x % 10 == 0){
      ans += x;
    }
    else{
      hmin = min(hmin,x % 10);
      x = x/10 + 1;
      x *= 10;
      ans += x;
    }
  }
  if(hmin == 100){
    cout << ans;
  }
  else{
    cout << ans - (10 - hmin);
  }
}