#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) { return a.second > b.second; }

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> red(n), blue(n);

  for (int i = 0; i < n; i++) {
    cin >> red[i].first >> red[i].second;
  }

  for (int i = 0; i < n; i++) {
    cin >> blue[i].first >> blue[i].second;
  }
  sort(blue.begin(), blue.end());
  sort(red.begin(), red.end(), cmp);

  vector<bool> is_used_red(n, false);

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int blue_x = blue[i].first;
    int blue_y = blue[i].second;
    for (int j = 0; j < n; j++) {
      if (is_used_red[j]) {
        continue;
      }
      int red_x = red[j].first;
      int red_y = red[j].second;
      if (red_x < blue_x && red_y < blue_y) {
        is_used_red[j] = true;
        ans++;
        break;
      }
    }
  }

  cout << ans << endl;
  return 0;
}