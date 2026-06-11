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
  ll n, a, b;
  cin >> n >> a >> b;
  
  cout << min(a, b) << " " << max(a+b-n, 0LL) << "\n";
  
  //cout << (  ?"Yes" :"No") << "\n";

}