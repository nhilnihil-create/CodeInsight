#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define repr(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define ALL(a) (a).begin(), (a).end()
using ll = long long;
// using Graph = vector<vector<int>>;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ll LINF = 1LL << 60;

int main() {
  int n, k, start;
  string s;
  cin >> n >> k >> s;
  if (s[0] == '0')
    start = 0;
  else
    start = 1;
  char f = s[0];
  int cnt = 0;
  vector<int> res;
  rep(i, n) {
    if (s[i] == f)
      cnt++;
    else {
      res.push_back(cnt);
      cnt = 1;
      f = s[i];
    }
  }
  res.push_back(cnt);
  // rep(i, res.size()) cout << res[i] << endl;
  int ans = 0;
  if (start == 1) {
    if (res.size() / 2 <= k) {
      rep(i, res.size()) ans += res[i];
      cout << ans << endl;
      return 0;
    }
    for (int i = 0; i < res.size() - 2 * k; i += 2) {
      int tmp = 0;
      for (int j = i; j < i + 2 * k + 1; ++j) tmp += res[j];
      ans = max(ans, tmp);
    }
    int tmp = 0;
    for (int j = res.size() - 1; j >= res.size() - 2 * k; --j) tmp += res[j];
    ans = max(ans, tmp);
  } else {
    if ((res.size() + 1) / 2 <= k) {
      rep(i, res.size()) ans += res[i];
      cout << ans << endl;
      return 0;
    }
    for (int i = 1; i <= res.size() - 1 - 2 * k; i += 2) {
      int tmp = 0;
      for (int j = i; j < (i + 2 * k + 1); ++j) tmp += res[j];
      ans = max(ans, tmp);
    }
    int tmp = 0;
    for (int j = res.size() - 1; j >= res.size() - 2 * k; --j) tmp += res[j];
    ans = max(ans, tmp);
    tmp = 0;
    for (int j = 0; j < 2 * k; ++j) tmp += res[j];
    ans = max(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}
