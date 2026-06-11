#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  int hash = 0, period = 0;
  rep(i, n) {
    if (s[i] == '.') period++;
  }
  int ans = period;
  rep(i, n) {
    if (s[i] == '#') {
      hash++;
    } else {
      period--;
    }
    ans = min(ans, hash + period);
  }
  cout << ans;
  return 0;
}
