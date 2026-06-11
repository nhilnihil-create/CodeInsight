#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>

intmax_t opt(
    const std::vector<intmax_t> &x, const std::vector<intmax_t> &v,
    intmax_t c) {

  size_t n=v.size();
  std::vector<intmax_t> vv(n);
  intmax_t sv=v[n-1];
  vv[n-1] = std::max<intmax_t>(0, sv-(c-x[n-1]));
  for (size_t i=n-1; i--;) {
    sv += v[i];
    vv[i] = std::max(vv[i+1], sv-(c-x[i]));
  }

  intmax_t res=std::max<intmax_t>(0, sv-x[n-1]);
  sv = 0;
  for (size_t i=0; i+1<n; ++i) {
    sv += v[i];
    res = std::max({res, sv-x[i], sv-x[i]-x[i]+vv[i+1]});
  }

  return res;
}

int main() {
  size_t N;
  intmax_t C;
  scanf("%zu %jd", &N, &C);

  std::vector<intmax_t> x1(N), v1(N);
  for (size_t i=0; i<N; ++i)
    scanf("%jd %jd", &x1[i], &v1[i]);

  std::vector<intmax_t> x2(N), v2(N);
  for (size_t i=0; i<N; ++i) {
    x2[i] = C-x1[N-i-1];
    v2[i] = v1[N-i-1];
  }

  printf("%jd\n", std::max(opt(x1, v1, C), opt(x2, v2, C)));
}
