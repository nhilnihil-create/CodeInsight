#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
  if(b > a) return gcd(b, a);
  if(b == 0) return a;
  return gcd(b, a % b);
}

int main(){
  ll T; cin >> T;
  
  for(ll t = 0; t < T; t++){
    ll a, b, c, d; cin >> a >> b >> c >> d;
    if((a < b)||(d < b)) {
      cout << "No" << endl;
      continue;
    }
    if(c > b){
      cout << "Yes" << endl;
      continue;
    }
    if(d > b){
      ll g = gcd(d, b);
      ll tmp = b - g + (a % g);
      if(tmp <= c) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
    if(d == b){
      if(a % b <= c) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  }
}