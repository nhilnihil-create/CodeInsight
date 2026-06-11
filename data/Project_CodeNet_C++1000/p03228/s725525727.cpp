#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(ll i = (s); i < (n); i++)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(18);
  
  ll a, b, k;
  cin >> a >> b >> k;
  
  rep(i, 0, k) {
    if(i%2==0) {
      if(a%2==1) a--;
      b += a/2;
      a /= 2;
    }
    else {
      if(b%2==1) b--;
      a += b/2;
      b /= 2;
    }
  }    
  
  cout << a << " " << b << "\n";
}