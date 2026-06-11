/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int32_t, int32_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

int32_t next_steps[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool IsValidPosition(const Pair &position, const int32_t N) {
  return position.first >= 0 && position.first <= 100000 && position.second >= 0 && position.second <= 100000;
}

int32_t CanReachWithinTime(const Pair &position, const Pair &target, const int32_t time_limit) {
  const int32_t distance = abs(position.first - target.first) + abs(position.second - target.second);
  return (distance <= time_limit && (time_limit - distance) % 2 == 0);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int32_t N;
  cin >> N;
  int32_t previous_time = 0;
  Pair previous_position = Pair(0, 0);
  bool is_okay = true;
  for (int32_t step = 0; step < N; ++step) {
    int32_t taraget_t;
    Pair target_pos;
    cin >> taraget_t >> target_pos.first >> target_pos.second;
    const int32_t dt = taraget_t - previous_time;

    if (!CanReachWithinTime(previous_position, target_pos, dt)) {
      is_okay = false;
    }

    previous_time = taraget_t;
    previous_position = target_pos;
  }
  if (is_okay) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
