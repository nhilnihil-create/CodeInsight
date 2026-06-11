#include <bits/stdc++.h>

int main() {
  int64_t n;
  std::cin >> n;
  std::vector<int64_t> t(n), v(n);
  for (auto &i : t) {
    std::cin >> i;
  }

  for (auto &i : v) {
    std::cin >> i;
  }

  std::vector<int64_t> t_b(n), t_e(n);
  t_b[0] = 0;
  for (int64_t i = 1; i < n; i++) {
    t_b[i] = t_b[i - 1] + t[i - 1];
  }
  t_e[0] = t[0];
  for (int64_t i = 1; i < n; i++) {
    t_e[i] = t_e[i - 1] + t[i];
  }
  const auto t_max = std::accumulate(t.cbegin(), t.cend(), 0);
  auto speed = [&] (double time) {
    double ans = std::min<double>(time, t_max - time);
    for (int j = 0; j < n; j++) {
      if (time < t_b[j]) {
        ans = std::min<double>(ans, t_b[j] - time + v[j]);
      } else if (t_b[j] <= time && time <= t_e[j]) {
        ans = std::min<double>(ans, v[j]);
      } else {
        ans = std::min<double>(ans, time - t_e[j] + v[j]);
      }
    }
    return std::max<double>(ans, 0.0);
  };

  double l = 0;
  for (double i = 0; i < t_max; i += 0.5) {
    l += 0.25 * (speed(i) + speed(i + 0.5));
  }
  std::cout << std::fixed << std::setprecision(2) << l << std::endl;
  return 0;
}
