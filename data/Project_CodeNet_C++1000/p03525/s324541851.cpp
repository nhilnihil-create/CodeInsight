#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

inline int mymod(int a, int m) { return (a % m + m) % m; }

int main() {
  int n;
  cin >> n;
  vector<int> count(13, 0);
  for (int i = 0; i < n; i += 1) {
    int d;
    cin >> d;
    count[d] += 1;
  }
  count[0]++;
  for (auto i : count) {
    if (i >= 3) {
      cout << 0 << endl;
      return 0;
    }
  }
  int ans = 0;
  for (int bit = 0; bit < (1 << 13); bit++) {
    // bitの下からi番目の位が立っている＝iの距離にある人を若いほうに割り当てる
    vector<int> a;
    for (int i = 0; i <= 12; i++) {
      if (count[i] == 0)
        continue;
      if (count[i] == 2) {
        a.push_back(i);
        a.push_back(24 - i);
        // 互いの距離を最大化したいので、両方に振り分けた方がいい
        continue;
      }
      if (bit >> i & 1) {
        a.push_back(i);
      } else {
        a.push_back(24 - i);
      }
    }
    int m = 13;
    for (int i = 0; i < a.size(); i++) {
      for (int j = i + 1; j < a.size(); j++) {
        m = min({m, mymod(a[i] - a[j], 24), mymod(a[j] - a[i], 24)});
      }
    }
    ans = max(ans, m);
  }
  cout << ans << endl;
}
