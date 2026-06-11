#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s; cin >> s;
  int sn = s.size();
  if (s[0] == 'A') {
    int cc = 0, j = 0;
    for (int i = 2; i<sn-1; i++) {
      if (s[i] == 'C') {
        j=i;
        cc++;
      }
    }
    if (cc == 1) {
      bool flag = true;
      for (int i = 1; i<sn; i++) {
        if (i==j) continue;
        if (isupper(s[i])) {
          flag = false;
          break;
        }
      }
      if (flag) {
        cout << "AC" << endl;
        return 0;
      }
    }
  }
  cout << "WA" << endl;
  return 0;
}