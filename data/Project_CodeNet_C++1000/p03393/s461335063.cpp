#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  cin >> s;
  int n = s.size();

  vector<int> used(26, 0);
  rep(i, n) used[s[i] - 'a'] = 1;

  string ans = "";
  if (n < 26) {
    rep(i, 26) if (used[i] == 0) {
      ans = s + (char)(i + 'a');
      break;
    }
  } else {
    for (int i = n-1; i >= 0; --i) {
      for (char c = s[i] + 1; c <= 'z'; ++c) {
        if (used[c-'a'] == 0) {
          rep(j, i) ans += s[j];
          ans += c;
          break;
        }
      }
      if (ans != "") break;
      used[s[i] - 'a'] = 0;
    }
  }
  if (ans == "") cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}