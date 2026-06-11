#include <stdio.h>
#include <stdlib.h>

#define MAX_N (100000L)
#define MAX_FACT (MAX_N)
#define NUM_MOD (1000000007L)

long fs[MAX_FACT + 1], finvs[MAX_FACT + 1], invs[MAX_FACT + 1];

long mod(long n, long k) { return n % k >= 0 ? n % k : n % k + k; }

void init() {
  fs[0] = fs[1] = 1;
  finvs[0] = finvs[1] = 1;
  invs[1] = 1;
  for (long i = 2; i <= MAX_FACT; i++) {
    fs[i] = fs[i - 1] * i % NUM_MOD;
    invs[i] = NUM_MOD - invs[NUM_MOD % i] * (NUM_MOD / i) % NUM_MOD;
    finvs[i] = finvs[i - 1] * invs[i] % NUM_MOD;
  }
}

int main(int argc, char *argv[]) {
  // read inputs
  long N, as[MAX_N];
  scanf("%ld", &N);
  for (int i = 0; i < N; i++) scanf("%ld", &as[i]);

  // initialize calculation of factorial and mod
  init();

  // calculate the number of times each element gets counted
  long cnts[MAX_N];
  // the first
  cnts[0] = 0;
  for (long i = 0; i < N; i++) {
    cnts[0] = mod(cnts[0] + fs[N] * invs[abs(0 - i) + 1], NUM_MOD);
  }
  // the rest
  for (long i = 1; i < N; i++) {
    cnts[i] = mod(cnts[i - 1] + fs[N] * invs[abs(i - 0) + 1] -
                      fs[N] * invs[abs(i - 1 - (N - 1)) + 1],
                  NUM_MOD);
  }
  for (long i = 0; i < N; i++) {
  }

  // calculate the answer
  long ans = 0;
  for (long i = 0; i < N; i++) {
    // printf("i = %ld, cnts[i] = %ld, as[i] = %ld, cnts[i] = as[i] = %ld\n", i,
    //        cnts[i], as[i], as[i] * cnts[i]);
    ans = mod(ans + as[i] * cnts[i], NUM_MOD);
  }
  printf("%ld\n", ans);

  return 0;
}
