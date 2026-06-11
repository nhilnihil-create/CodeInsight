#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  int t = 0, x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    int tt, xt, yt;
    cin >> tt >> xt >> yt;
    int tm = tt - t;
    int dist = abs(x - xt) + abs(y - yt);
    if (dist > tm) {
      puts("No");
      return 0;
    } else if ((tm - dist) & 1) {
      puts("No");
      return 0;
    }
    t = tt;
    x = xt;
    y = yt;
  }
  puts("Yes");
  return 0;
}