#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  // KEYENCE String
  string s; cin >> s;
  string ans = "NO";
  int sn = s.size();
  rep(i,7) {
    string t;
    t += s.substr(0, i) + s.substr(sn - (7 - i));
    //cout << t << endl;
    if (t == "keyence") {
      ans = "YES";
      break;
    }
  }
  cout << ans << endl;
  return 0;
}