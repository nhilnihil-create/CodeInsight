#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> vec(n);
  for (auto &v : vec)
    cin >> v;
  sort(vec.begin(), vec.end());
  int ans = INT_MAX;
  for (int i = 0; i + k - 1 < n; ++i)
    ans = min(ans, vec[i+k-1] - vec[i]);
  cout << ans << endl;
}