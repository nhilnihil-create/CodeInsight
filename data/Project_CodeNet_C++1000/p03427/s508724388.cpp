#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  int n = (int) s.size();
  int sm = 0;
  for (char &c : s) {
    c -= '0';
    sm += c;
  }
  for (int i = 0; i < n; i++) {
    if (s[i] != '0') {
      cout << max(sm, s[i] - 1 + 9 * (n - 1 - i)) << '\n';
      return 0;
    }
  }
}
