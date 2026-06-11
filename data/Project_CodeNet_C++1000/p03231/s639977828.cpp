#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
  if(a%b==0LL) return b;
  return gcd(b, a%b);
}

int main(){
  ll n, m; cin >> n >> m;
  string s, t;  cin>> s >> t;
  ll g = gcd(n, m);
  ll ans= n/g*m;

  if(s!=t && n==m) ans = -1;
  else{
    n /= g; m /= g;
    for(ll i=0; i<g; i++){
      if(s[i*n]==t[i*m]) continue;
      ans = -1;
    }
  }

    cout << ans << endl;

  
  
}
