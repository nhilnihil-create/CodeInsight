#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(ll i = (s); i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()



int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(18);
  
  string s;
  ll ans = 0;
  cin >> s;
  
  //vector<ll> a(n); 
  rep(i, 0, 4) {
    if(s[i] == '2') ans++;
  }
  
  cout << ans << "\n";
  
  //cout << (  ?"Yes" :"No") << "\n";

}