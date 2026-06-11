#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int h, w, n;
  cin >> h >> w >> n;
  vector<pair<int, int>> o(n);
  for (int i = 0; i < n; ++i) {
    int r, c;
    cin >> o[i].first >> o[i].second;
  }
  sort(o.begin(), o.end());
  int b = 0, ans = h + 1;
  for (auto p : o) {
    int y = p.first, x = p.second;
    if (y - x == b) {
      ++b;
    } else if (y - x > b) {
      ans = y;
      break;
    }
  }
  cout << ans - 1 << endl;
  return 0;
}