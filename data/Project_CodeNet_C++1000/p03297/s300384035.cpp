#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

ll gcd(ll a, ll b){
  if(b == 0) return a;
  return gcd(b, a % b);
}

int main(){
  int t;
  cin >> t;
  vector<bool> ans(t,false);
  rep(i,t) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if(c >= b && d >= b && a >= b) {
      ans[i] = true;
    } else if(a >= b && d >= b) {
      ll m = a % b;
      ll g = gcd(b,d);
      ll l = (c-m+g)/g, r = (b-1-m)/g;
      if(!(r >= l)) ans[i] = true;
    }
  }
  for(auto k : ans) cout << (k? "Yes" : "No") << endl;
  return 0;
}