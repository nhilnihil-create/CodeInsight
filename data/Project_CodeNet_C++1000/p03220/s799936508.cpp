#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, t, a;
  cin >> n >> t >> a;
  vector<int> vec(n);
  for (auto &v : vec)
    cin >> v;

  double delta_min = 1e9;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    double tmp = t - vec[i] * 0.006;
    double delta = abs(tmp - a);
    if (delta_min < delta)
      continue;
    delta_min = delta;
    ans = i + 1;
  }
  cout << ans << endl;
}