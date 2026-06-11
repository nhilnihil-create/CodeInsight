#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  if (s.find("BW") == s.npos) {
    cout << 0 << endl;
    return 0;
  }

  int start = s.find("B");
  int64_t ans = 0;
  int left = start;
  for (uint i = start; i < s.length(); i++) {
    if (s[i] == 'W') {
      ans += (i - left);
      left++;
    }
  }
  cout << ans << endl;

  return 0;
}
