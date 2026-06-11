#include <stdio.h>
#include <stdlib.h>

long sum_digits(long n) {
  long ret = 0;
  while (n > 0) {
    ret += n % 10;
    n /= 10;
  }
  return ret;
}

int main(int argc, char *argv[]) {
  // read inputs
  long K;
  scanf("%ld", &K);

  // solve
  long n = 1, s_n = 1, d = 1;
  for (long k = 0; k < K; k++) {
    for (;; d *= 10) {
      n = (n / d) * d + (d - 1);
      s_n = sum_digits(n);
      long m = n + d, s_m = sum_digits(m);
      // printf("m = %ld, s_m = %ld, n = %ld, s_n = %ld, d = %ld\n", m, s_m, n,
      //        s_n, d);
      if (n * s_m <= m * s_n) {
        break;
      }
    }
    printf("%ld\n", n);
    n++;
    s_n = sum_digits(n);
  }

  return 0;
}
