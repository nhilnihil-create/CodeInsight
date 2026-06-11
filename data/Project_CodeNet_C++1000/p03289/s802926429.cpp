#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  string res = "AC";
  if (s[0] != 'A') {
    res = "WA";
  }
  int cnt = 0;
  for (int i = 1; i < s.size(); i++) {
    if (isupper(s[i])) {
      if (i == 1 || i == s.size() - 1 || s[i] != 'C') {
        res = "WA";
      }
      cnt++;
    }
  }
  if (cnt != 1) {
    res = "WA";
  }
  cout << res << endl;
  return 0;
}