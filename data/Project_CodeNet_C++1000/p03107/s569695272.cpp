#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;
  int red = 0;
  int blue = 0;
  for (char c : s) {
    if (c == '0') {
      red++;
    } else if (c == '1') {
      blue++;
    }
  }
  cout << min(red, blue) * 2 << endl;
  return 0;
}
