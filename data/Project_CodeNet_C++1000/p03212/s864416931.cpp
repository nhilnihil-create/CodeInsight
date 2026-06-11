/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using Pair = pair<int64_t, int64_t>;
constexpr int64_t kInf = INT64_MAX / 2L;

// std::cout << std::setprecision(20) << 1.1 << endl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t N;
  cin >> N;

  const int64_t keys[] = {7, 5, 3};
  int64_t result = 0;
  auto Dfs = [&](auto &&Func, vector<int64_t> num, const int64_t digit) -> void {
    int64_t L = static_cast<int64_t>(num.size());
    if (L == digit) {
      vector<bool> is_okay(3, false);
      for (const auto n : num) {
        if (n == 7) {
          is_okay[0] = true;
        } else if (n == 5) {
          is_okay[1] = true;
        } else if (n == 3) {
          is_okay[2] = true;
        }
      }
      int64_t cval = 0;
      for (const auto v : num) {
        cval *= 10;
        cval += v;
      }
      if (cval <= N && is_okay[0] && is_okay[1] && is_okay[2]) {
        ++result;
      }
    } else {
      for (const auto &key : keys) {
        num.push_back(key);
        Func(Func, num, digit);
        num.pop_back();
      }
    }
  };
  vector<int64_t> nums;

  for (int64_t digit = 1; digit <= 9; ++digit) {
    Dfs(Dfs, nums, digit);
  }
  cout << result << endl;
  return 0;
}
