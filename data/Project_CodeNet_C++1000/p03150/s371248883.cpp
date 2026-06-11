#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  // KEYENCE String
  string s; cin >> s;
  string ans = "NO", t="keyence";
  int c = 0, sn = s.size(), tn = t.size();
  int r = 0;
  int l = tn-1;

  rep(i,sn) {
    if (s[i] == t[r]) {
      r++;
      c++;
    }
    else break;
  }

  for (int i = sn-1; i>r; i--) {
    if (s[i] == t[l]) {
      l--;
      c++;
    }
    else break;
  }

  if (c==7) ans = "YES";
  cout << ans << endl;
  return 0;
}