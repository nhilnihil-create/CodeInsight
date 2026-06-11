#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int digit_sum(string s) {
  int ans = 0;
  rep(i, s.size()) ans += s[i] - '0';
  return ans;
}

int main() {
  string s, t;
  cin >> s;
  t = s;
  rep(i, t.size() - 1) { t[i + 1] = '9'; }

  int ans = digit_sum(t);
  if (s == t) {
    cout << ans << endl;
  } else {
    cout << ans - 1 << endl;
  }
  return 0;
}
