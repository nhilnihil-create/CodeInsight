#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>

template <class Tp>
Tp gcd(Tp m, Tp n) {
  while (n) std::swap(m%=n, n);
  return m;
}

int solve_testcase() {
  intmax_t A, B, C, D;
  scanf("%jd %jd %jd %jd", &A, &B, &C, &D);

  if (A < B) return puts("No"), 0;
  if (D < B) return puts("No"), 0;
  if (C >= B) return puts("Yes"), 0;

  intmax_t g = gcd(B, D);
  if ((A%g) + B-g > C) return puts("No"), 0;
  puts("Yes");
  return 0;
}

int main() {
  int T;
  scanf("%d", &T);

  for (int i=0; i<T; ++i)
    solve_testcase();
}
