#include <stdio.h>
#include <cmath>

long double nth_root(long double val, long double num)
{
  long double inverse = std::pow(num, -1);
  long double ln = std::log(val);
  return std::exp(inverse * ln);
}

int main()
{
  long long N, P;
  scanf("%lld%lld", &N, &P);

  long long ans = 1;
  long long loop = nth_root(P, N) + 0.5;
  for (long long i = loop; i > 1; i--) {
    long long temp = P;
    bool flag = true;
    for (int j = 0; j < N; j++) {
      if (temp % i != 0) {
        flag = false;
        break;
      }
      temp /= i;
    }
    if (flag) {
      ans = i;
      break;
    }
  }

  printf("%lld\n", ans);
  return 0;
}
