#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  if (n == 0) {
    cout << 0 << '\n';
    return 0;
  }

  string ans;
  while (n) {
    int r = n % 2;
    if (r < 0) {
      r += 2;
    }

    ans += '0' + r;
    n -= r;
    n /= -2;
  }

  reverse(ans.begin(), ans.end());
  cout << ans << '\n';
}