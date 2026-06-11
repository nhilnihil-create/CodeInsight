#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  int x, y;
  cin >> x >> y;
  --x, --y;
  string s, t;
  cin >> s >> t;
  int left = y;
  int right = y;
  int up = x;
  int down = x;
  for (int i = 0; i < k; i++) {
    if (s[i] == 'R') ++right;
    if (s[i] == 'D') ++down;
    if (s[i] == 'U') --up;
    if (s[i] == 'L') --left;
    if (right == m || left < 0 || down == n || up < 0) {
      cout << "NO" << '\n';
      return 0;
    }
    if (t[i] == 'R' && left + 1 < m) ++left;
    if (t[i] == 'D' && up + 1 < n)   ++up;
    if (t[i] == 'U' && down > 0)     --down;
    if (t[i] == 'L' && right > 0)    --right;
  }
  cout << "YES" << '\n';
  return 0;
}
