#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s; cin >> s;
  int ans = s.size();
  for (int i = 0; i < s.size() - 1; i++) {
    if (s[i] != s[i + 1]) {
      ans = min(ans, max(i + 1, (int) s.size() - i - 1));
    }
  }
  cout << ans << endl;
  return 0;
}