#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s, t;
  cin >> s >> t;
  int ns = s.size(), nt = t.size();
  bool flag1 = false;
  for (int i = ns - nt; i >= 0; i--) {
    bool flag = true;
    rep(j, nt) if (s[i + j] != '?') flag &= (t[j] == s[i + j]);
    if (flag) {
      rep(j, nt) s[i + j] = t[j];
      flag1 = true;
      break;
    }
  }
  if (!flag1) {
    cout << "UNRESTORABLE" << endl;
    return 0;
  }
  rep(i, ns) if (s[i] == '?') s[i] = 'a';
  cout << s << endl;
  return 0;
}
