#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<int, int>;

int main() {
  string s, t;
  cin >> s >> t;

  int k = -1;
  int S = s.length();
  int T = t.length();
  rep(i, S - T + 1) {
    bool ok = true;
    rep(j, T) {
      if (s[i + j] != t[j] && s[i + j] != '?') {
        ok = false;
      }
    }
    if (ok) k = i;
  }
  if (k == -1) {
    cout << "UNRESTORABLE" << endl;
  } else {
    rep(i, T) s[i + k] = t[i];
    rep(i, S) s[i] = (s[i] == '?') ? 'a' : s[i];
    cout << s << endl;
  }
}
