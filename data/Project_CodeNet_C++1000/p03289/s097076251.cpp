#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  string ans = "AC";
  if (s[0] != 'A') ans = "WA";
  int cnt = 0;
  for (int i = 1; i < s.size(); i++) {
    if ('A' <= s[i] && s[i] <= 'Z') {
      if (i == 1 || i == s.size() - 1 || s[i] != 'C') ans = "WA";
      cnt++;
    }
  }
  if (cnt != 1) ans = "WA";
  cout << ans << endl;
}