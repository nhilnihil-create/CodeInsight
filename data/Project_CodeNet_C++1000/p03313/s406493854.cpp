#include <cstddef>
#include <vector>

template <class S>
void subset_zeta_transform(std::vector<typename S::value_type> &a) {
  using size_t = std::size_t;

  const size_t n = a.size();
  for (size_t i = 1; i < n; i *= 2) {
    for (size_t j = 0; j != n; j += 1) {
      if ((j & i) != 0)
        a[j] = S::operation(a[j & ~i], a[j]);
    }
  }
}

template <class S>
void superset_zeta_transform(std::vector<typename S::value_type> &a) {
  using size_t = std::size_t;

  const size_t n = a.size();
  for (size_t i = 1; i < n; i *= 2) {
    for (size_t j = 0; j != n; j += 1) {
      if ((j & i) != 0)
        a[j & ~i] = S::operation(a[j & ~i], a[j]);
    }
  }
}

template <class G>
void subset_mobius_transform(std::vector<typename G::value_type> &a) {
  using size_t = std::size_t;

  const size_t n = a.size();
  size_t i = 1;
  while (i < n)
    i *= 2;
  while (i != 1) {
    i /= 2;
    for (size_t j = 0; j != n; j += 1) {
      if ((j & i) != 0)
        a[j] = G::operation(G::inverse(a[j & ~i]), a[j]);
    }
  }
}

template <class G>
void superset_mobius_transform(std::vector<typename G::value_type> &a) {
  using size_t = std::size_t;

  const size_t n = a.size();
  size_t i = 1;
  while (i < n)
    i *= 2;
  while (i != 1) {
    i /= 2;
    for (size_t j = 0; j != n; j += 1) {
      if ((j & i) != 0)
        a[j & ~i] = G::operation(a[j & ~i], G::inverse(a[j]));
    }
  }
}

#include <algorithm>
#include <array>
#include <functional>
#include <iostream>

struct top2 {
  using value_type = std::array<int, 2>;

  static value_type operation(const value_type &l, const value_type &r) {
    std::array<int, 4> v = {l[0], l[1], r[0], r[1]};
    std::sort(v.begin(), v.end(), std::greater<int>());
    return {v[0], v[1]};
  }
  static constexpr value_type identity = {0, 0};
};
constexpr typename top2::value_type top2::identity;

int main() {
  int n;
  std::cin >> n;
  std::vector<top2::value_type> a(1 << n);

  for (auto &e : a) {
    std::cin >> e[0];
  }

  subset_zeta_transform<top2>(a);
  a.erase(a.begin());
  int cur = 0;
  for (const auto &e : a) {
    cur = std::max(cur, e[0] + e[1]);
    std::cout << cur << std::endl;
  }
}