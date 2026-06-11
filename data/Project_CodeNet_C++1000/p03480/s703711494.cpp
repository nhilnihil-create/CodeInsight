#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  int sl = s.length();
  int flag, ans = 0;

  for (int i = sl; i >= sl / 2; i--) {
    for (int j = sl - i; j < i; j++) {
      if (j == sl - i) flag = s[j];
      if (flag != s[j]) break;
      if (j == i - 1) ans = i;
    }
    if (ans != 0) break;
  }

  if (ans == 0) ans = sl / 2;

  cout << ans << endl;


  return 0;

}