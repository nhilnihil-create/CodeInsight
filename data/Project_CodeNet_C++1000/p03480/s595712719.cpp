#include <iostream>
#include <algorithm>
using namespace std;
int main(void) {
  string s;
  cin >> s;
  int n = (int)(s.length());
  int ans = n;
  for (int i = 1; i < n; i++) {
    if (s[i] != s[i - 1]) {
      ans = min(ans, max(i, n - i));
    }
  }
  cout << ans << endl;
  return 0;
}