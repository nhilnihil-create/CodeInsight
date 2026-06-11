#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  int sum;
  for (int bit = 0; bit < (1 << (s.size() - 1)); bit++) {
    sum = s[0] - '0';
    rep(i, s.size() - 1) {
      if (bit & (1 << i)) {
        sum += s[i + 1] - '0';
      } else {
        sum -= s[i + 1] - '0';
      }
    }
    if (sum == 7) {
      cout << s[0];
      rep(i, s.size() - 1) {
        if (bit & (1 << i)) {
          cout << "+" << s[i + 1];
        } else {
          cout << "-" << s[i + 1];
        }
      }
      cout << "=7" << endl;
      return 0;
    }
  }

  return 0;
}