#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;

  int ans = 0;
  int l = 0, r = 0, c = 0;
  while (l < n) {
    while ((c < k || (c == k && s[r + 1] == '1')) && r < n - 1) {
      if (s[r] == '0' && s[r + 1] == '1') {
        ++c;
      }
      ++r;
    }

    ans = max(ans, r - l + 1);

    while (l < n) {
      ++l;
      if (s[l - 1] == '0' && s[l] == '1') {
        --c;
        break;
      }
    }
  }
  cout << ans << endl;
}