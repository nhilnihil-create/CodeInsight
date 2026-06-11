/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int64_t, int64_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t N, M;
  cin >> N >> M;
  priority_queue<Pair> q;
  for (int64_t i = 0; i < N; ++i) {
    int64_t a;
    cin >> a;
    q.emplace(Pair(a, 1));
  }
  for (int64_t j = 0; j < M; ++j) {
    int64_t b, c;
    cin >> b >> c;
    q.emplace(Pair(c, b));
  }

  int64_t result = 0;
  while (!q.empty()) {
    const Pair p = q.top();
    q.pop();
    const int64_t card = p.first;
    const int64_t count = p.second;
    const int64_t counted = min(N, count);
    result += card * counted;
    N -= counted;
    if (N <= 0) {
      break;
    }
  }
  cout << result << endl;
  return 0;
}
