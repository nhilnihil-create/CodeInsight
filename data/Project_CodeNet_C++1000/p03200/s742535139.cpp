#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  long long res = 0;
  int cnt = 0;
  for (char c : s) {
    if (c == 'W') {
      res += cnt;
    } else {
      ++cnt;
    }
  }
  cout << res << '\n';
  return 0;
}
