#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;
  bool prevIsWhite = false;
  int res = 0;
  for (int i = 0; i < s.size(); i++) {
    char c = s[i];
    if (c == '1') {
      if (prevIsWhite && i != 0) {
        res++;
        prevIsWhite = false;
      } else {
        prevIsWhite = true;
      }
    } else {
      if (!prevIsWhite && i != 0) {
        res++;
        prevIsWhite = true;
      } else {
        prevIsWhite = false;
      }
    }
  }
  cout << res << endl;
  return 0;
}
