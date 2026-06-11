#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string s;
  cin >> s;

  int ans = 0;
  int l = 0, r = s.length() - 1;
  while (l < r) {
    if (s[l] == s[r]) {
      l++;
      r--;
    } else if (s[l] == 'x') {
      ans++;
      l++;
    } else if (s[r] == 'x') {
      ans++;
      r--;
    } else {
      ans = -1;
      break;
    }
  }

  cout << ans << endl;

  return 0;
}