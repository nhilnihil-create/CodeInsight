#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = (int)s.size();
  ll cnt = 0, ans = 0;
  rep(i, n) {
    if (s[i] == 'W') {
      ans += i - cnt;
      cnt++;
    }
  }
  cout << ans;
  return 0;
}