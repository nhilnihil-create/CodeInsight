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
  priority_queue<int64_t> q;
  for (int64_t i = 0; i < N; ++i) {
    int64_t a;
    cin >> a;
    q.emplace(a);
  }
  while (!q.empty()) {
    const int64_t t = q.top();
    q.pop();
    const int64_t n = q.top();
    if (n == 0) {
      q.emplace(t);
      break;
    }
    q.emplace(t % n);
  }
  cout << q.top() << endl;
  return 0;
}
