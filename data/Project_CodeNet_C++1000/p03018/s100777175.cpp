#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  int cnt = 0;
  long long ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (i > 0 && s[i - 1] == 'B' && s[i] == 'C') {
      cnt += 2;
      i -= 1;
    } else if (s[i] == 'A') {
      ans += cnt / 2;
    } else {
      cnt = 0;
    }
  }
  cout << ans << '\n';
  return 0; // :)
}
