#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s, t;
  cin >> s >> t;
  int ls = s.size();
  int lt = t.size();
  string ans = "UNRESTORABLE";
  for (int si = 0; si + lt - 1 < ls; si++) {
    string ss = s;
    bool same = true;
    rep(i, lt) { 
      if (ss[si + i] == '?') ss[si + i] = t[i];
      if (ss[si + i] != t[i]) same = false;
    }
    if (!same) continue;
    rep(i, ls) if (ss[i] == '?') ss[i] = 'a';
    ans = ss;
  }
  cout << ans << endl;
  return 0;
}