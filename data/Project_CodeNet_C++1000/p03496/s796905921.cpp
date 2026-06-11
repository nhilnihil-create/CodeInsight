#include <bits/stdc++.h>

int main() {
  int n;
  std::cin >> n;
  std::vector<int64_t> a(n);
  for (auto &i : a) {
    std::cin >> i;
  }

  std::vector<int64_t> b(n);
  for (int i = 0; i < n; i++) {
    b[i] = std::abs(a[i]);
  }

  auto get_max = [&](const auto s, const auto e) {
    int r = s;
    int64_t val = b[r];

    for (int i = s; i < e; i++) {
      if (val < b[i]) {
        r = i;
        val = b[i];
      }
    }
    return r;
  };

  int s = 0, e = n;

  while (s != e) {
    const auto i = get_max(s, e);
    if (0 < a[i]) {
      e = i;
    } else if (a[i] < 0) {
      s = i + 1;
    } else {
      s = e = i;
    }
  }

  std::vector<std::pair<int, int>> ans;
  for (int i = s - 1; 0 < i; i--) {
    if (a[i] < a[i - 1]) {
      ans.push_back({i, i - 1});
      a[i - 1] += a[i];
    }
    if (a[i] < a[i - 1]) {
      ans.push_back({i, i - 1});
      a[i - 1] += a[i];
    }
  }

  for (int i = e; i < n - 1; i++) {
    if (a[i + 1] < a[i]) {
      ans.push_back({i, i + 1});
      a[i + 1] += a[i];
    }
    if (a[i + 1] < a[i]) {
      ans.push_back({i, i + 1});
      a[i + 1] += a[i];
    }
  }

  std::cout << ans.size() << std::endl;
  for (const auto &i : ans) {
    std::cout << i.first + 1 << " " << i.second + 1 << std::endl;
  }

  return 0;
}