#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int h, w, n;
  int st_x, st_y;
  cin >> h >> w >> n;
  cin >> st_x >> st_y;
  st_x--;
  st_y--;
  std::string s, t;
  cin >> s >> t;

  // For up/down, we want 0 <= st_x < n
  // --> [lower, upper]
  auto check = [&](char pos, char neg, int lower, int upper, int cur_balance) {
    for (int i = 0; i < n; i++) {
      bool s_is = s[i] == pos;
      bool t_is = t[i] == neg;

      cur_balance += s_is;
      if (cur_balance > upper) {
        return true;
      }
      if (cur_balance > lower) {
        cur_balance -= t_is;
      }
    }
    return false;
  };

  auto res1 = check('U', 'D', 0, h - 1, h - 1 - st_x);
  auto res2 = check('D', 'U', 0, h - 1, st_x);
  auto res3 = check('L', 'R', 0, w - 1, w - 1 - st_y);
  auto res4 = check('R', 'L', 0, w - 1, st_y);
  if (res1 || res2 || res3 || res4) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}