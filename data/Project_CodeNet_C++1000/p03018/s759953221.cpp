#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define repr(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define ALL(a) (a).begin(), (a).end()
using ll = long long;
using Graph = vector<vector<int>>;
const ll mod = 1e9 + 7;
const ll INF = 1e9;
const ll LINF = 1LL << 60;

int main() {
  string s;
  string t = "";
  cin >> s;
  ll ans = 0, cnt = 0;
  rep(i, s.length() - 1) {
    if (s[i] == 'B' && s[i + 1] == 'C') {
      t += 'D';
      ++i;
    } else {
      t += s[i];
    }
  }
  rep(i, t.length()) {
    if (t[i] == 'A')
      cnt++;
    else if (t[i] == 'D')
      ans += cnt;
    else
      cnt = 0;
  }
  cout << ans << endl;
  return 0;
}