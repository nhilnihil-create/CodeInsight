#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s, t; cin >> s >> t;
  int sn = s.size();
  string ans = "No";
  rep(i,sn) {
    if (s == t) ans = "Yes";
    s =  s.back() + s.substr(0,sn-1);
  }
  cout << ans << endl;
  return 0;
}