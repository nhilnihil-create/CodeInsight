#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){
  ll n, m;
  cin >> n >> m;
  ll g = __gcd(n, m);
  ll l = n/g*m;
  string s, t;
  cin >> s >> t;
  for(ll i = 0; ; i++){
    ll ns = i*(l/m), nt = i*(l/n);
    if(ns >= n || nt >= m) break;
    if(s.at(ns) != t.at(nt)){
      cout << -1 << endl;
      return 0;
    }
  }
  cout << l << endl;
  return 0;
}