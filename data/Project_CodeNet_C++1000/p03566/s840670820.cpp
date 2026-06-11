
#include <bits/stdc++.h>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> t(n), v(n);
  for (auto &i : t) {
    std::cin >> i;
  }

  for (auto &i : v) {
    std::cin >> i;
  }

  std::vector<int> t_b(n), t_e(n);
  t_b[0] = 0;
  for (int i = 1; i < n; i++) {
    t_b[i] = t_b[i - 1] + t[i - 1];
  }
  std::copy(std::next(t_b.cbegin()), t_b.cend(), t_e.begin());
  t_e.back() = t_b.back() + t.back();

  std::vector<int> v_max(t_e.back() + 1, 100);

  for (int i = 0; i < n; i++) {
    for (int j = t_b[i]; j <= t_e[i]; j++) {
      v_max[j] = std::min(v[i], v_max[j]);
    }
  }
  v_max.back() = 0;
  for (int i = n - 1; 0 <= i; i--) {
    auto j = t_e[i];
    auto val = v_max[j];
    while (0 < j && val + 1 < v_max[j - 1]) {
      v_max[j - 1] = val + 1;
      val++;
      j--;
    }
  }

  std::vector<int> v_ans(t_e.back() + 1);
  v_ans.front() = 0;

  for (int i = 1; i < v_ans.size(); i++) {
    v_ans[i] = std::min(v_max[i], v_ans[i - 1] + 1);
  }

  double l = 0;
  for (int i = 0; i < n; i++) {
    for (int j = t_b[i]; j < t_e[i]; j++) {
      if (v_ans[j] < v_ans[j + 1]) {
        l += v_ans[j] + 0.5;
      } else if (v_ans[j + 1] < v_ans[j]) {
        l += v_ans[j] - 0.5;
      } else if (v_ans[j] < v[i]) {
        l += v_ans[j] + 0.25;
      } else {
        l += v_ans[j];
      }
    }
  }

  std::cout << std::fixed << std::setprecision(2) << l << std::endl;
  return 0;
}
