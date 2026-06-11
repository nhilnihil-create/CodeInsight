#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int ans = 0;
  int l = 0, r = s.length();
  while (l < r) {
    if (s[l] != s[r - 1]) {
      if (s[l] == 'x') {
        ans++;
        l += 1;
      } else if (s[r - 1] == 'x') {
        ans++;
        r -= 1;
      } else {
        ans = -1;
        break;
      }
    } else {
      l += 1;
      r -= 1;
    }
  }
  cout << ans << '\n';
}