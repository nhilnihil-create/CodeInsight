#include <algorithm>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct item {
  int p;
  int y;
  int idx;
  int rank;
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<item> vec(m);
  for (int i = 0; i < m; ++i) {
    int p, y;
    cin >> p >> y;
    vec[i] = {p, y, i, 1};
  }

  sort(vec.begin(), vec.end(), [](auto &lhs, auto &rhs) {
    return lhs.p != rhs.p ? lhs.p < rhs.p : lhs.y < rhs.y;
  });

  for (int i = 1; i < m; ++i)
    if (vec[i - 1].p == vec[i].p)
      vec[i].rank = vec[i - 1].rank + 1;

  sort(vec.begin(), vec.end(),
       [](auto &lhs, auto &rhs) { return lhs.idx < rhs.idx; });

  for (auto &v : vec) {
    cout << setfill('0') << right << setw(6) << v.p;
    cout << setfill('0') << right << setw(6) << v.rank << endl;
  }

}
