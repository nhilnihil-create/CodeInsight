#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> vec(n);
  for (auto &v : vec) {
    int a, b;
    cin >> a >> b;
    v = make_pair(a, b);
  }

  sort(vec.begin(), vec.end(), [](auto &lhs, auto &rhs) {
    return (lhs.first + lhs.second) > (rhs.first + rhs.second);});

  ll ans = 0;
  for (int i = 0; i < n; ++i)
    ans += i % 2 == 0 ? vec[i].first : -vec[i].second;

  cout << ans << endl;
}
