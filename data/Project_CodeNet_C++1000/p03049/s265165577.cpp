#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  ll n, ans = 0;
  cin >> n;
  string s[n];
  ll ra = 0, lb = 0, ba = 0;
  rep(i, n) {
    cin >> s[i];
    rep(j, s[i].size() - 2) if (s[i][j] == 'A' && s[i][j + 1] == 'B') ans++;
    if (s[i][0] == 'B' && s[i][s[i].size() - 1] == 'A')
      ba++;
    else if (s[i][0] == 'B')
      lb++;
    else if (s[i][s[i].size() - 1] == 'A')
      ra++;
  }
  // cout << ba << " " << lb << " " << ra << " " << ans << endl;
  // ll mx = max(lb, ra);
  // ll mn = min(lb, ra);
  // ans = ans + mn + min(mx - mn, ba) + max(ba - (mx - mn), 0ll) / 2;
  if (ba == 0)
    ans += min(lb, ra);
  else {
    if (lb + ra > 0)
      ans += ba + min(lb, ra);
    else
      ans += ba - 1;
  }
  cout << ans << endl;
  return 0;
}
