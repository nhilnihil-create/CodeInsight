#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, h;
  cin >> n >> h;

  int max_a = 0;
  vector<pair<int, int>> vec(n);
  for (auto &v : vec) {
    int a, b;
    cin >> a >> b;
    v = make_pair(a, b);
    max_a = max(max_a, a);
  }

  sort(vec.begin(), vec.end(),
       [](auto &lhs, auto &rhs) { return lhs.second > rhs.second; });

  int cnt = 0;
  for (auto &v : vec) {
    int a = v.first;
    int b = v.second;
    if (max_a < b) {
      h -= b;
      ++cnt;
    }
    if (h <= 0)
      break;
  }
  if (0 < h)
    cnt += h / max_a + (h % max_a != 0);
  cout << cnt << endl;
}
