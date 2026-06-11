#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
  vector<int> vec(5);
  for (auto &v : vec)
    cin >> v;
  sort(vec.begin(), vec.end());
  int ans = INT_MAX;
  do {
    int tmp = 0;
    for (int i = 0; i < 4; ++i)
      tmp += (vec[i] + 9) / 10 * 10;
    tmp += vec[4];
    ans = min(ans, tmp);
  } while(next_permutation(vec.begin(), vec.end()));
  cout << ans << endl;
}