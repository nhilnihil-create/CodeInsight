#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  string S, T;
  cin >> S >> T;
  int m = -1;
  rep(i, S.size() - T.size() + 1) {
    bool ok = true;
    rep(j, T.size()) {
      if (S[j + i] != '?' && S[j + i] != T[j]) {
        ok = false;
      }
    }
    if (ok) {
      m = i;
    }
  }
  if (m != -1) {
    string ans = "";
    rep(i, m) {
      if (S[i] != '?') {
        ans += S[i];
      } else {
        ans += "a";
      }
    }
    ans += T;
    for (int i = m + T.size(); i < S.size(); i++) {
      if (S[i] != '?') {
        ans += S[i];
      } else {
        ans += "a";
      }
    }
    cout << ans << endl;
  } else {
    cout << "UNRESTORABLE" << endl;
  }
  return 0;
}