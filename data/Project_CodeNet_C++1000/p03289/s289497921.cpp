#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s; cin >> s;
  int sn = s.size();
  string ans = "AC";
  if (s[0] != 'A') {
    ans = "WA";
  } else {
    int cc = 0, j = 0;
    for (int i = 1; i<sn; i++) {
      if (isupper(s[i])) {
        if (2 <= i && i < sn - 1 && s[i] == 'C') {
          cc++;
        } else {
          ans = "WA";
        }
      }
    }
    if (cc != 1) ans = "WA";
  }
  cout << ans << endl;
  return 0;
}