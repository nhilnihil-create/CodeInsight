#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n,m;
  string s,t;
  cin >> n >> m >> s >> t;
  ll gcd = __gcd(n,m);
  ll ans = n/gcd*m;
  rep(i,0,gcd){
    if(s[i*n/gcd] != t[i*m/gcd]){cout << -1 << endl;return 0;}
  }
  cout << ans << endl;
}