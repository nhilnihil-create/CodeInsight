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
#include <cstdio>
#include <functional>

int scan() {
  int r = 0, c;
  while ((c = getchar_unlocked() - '0') >= 0)
    r = r * 10 + c;
  return r;
}

struct top2 {
  using value_type = std::array<int, 2>;

  static value_type operation(const value_type &l, const value_type &r) {
    if (l[0] > r[0])
      return {l[0], std::max(l[1], r[0])};
    else
      return {r[0], std::max(l[0], r[1])};
  }
  static constexpr value_type identity = {0, 0};
};
constexpr typename top2::value_type top2::identity;

int main() {
  const int n = scan();
  std::vector<top2::value_type> a(1 << n);

  for (auto &e : a) {
    e[0] = scan();
  }

  subset_zeta_transform<top2>(a);
  int cur = 0;
  const int s = 1 << n;
  for (int i = 1; i != s; i += 1) {
    cur = std::max(cur, a[i][0] + a[i][1]);
    printf("%d\n", cur);
  }
  return 0;
}