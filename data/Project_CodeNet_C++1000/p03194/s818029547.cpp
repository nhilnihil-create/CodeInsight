#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <utility>
using namespace std;
int main() {
  unsigned long n, p;
  cin >> n >> p;
  vector<pair<unsigned long, unsigned long>> factors;
  // prime factorize p
  for(unsigned long i=2;i<=p;i++) {
    unsigned long j = 0;
    if (i > sqrt(p)) {
      if (i < p) {
        factors.push_back({p, 1});
      }
      break;
    }
    for(j=0;p%i == 0;j++) {
      p = p/i;
    }
    if (j > 0) {
      factors.push_back({i, j});
    }
  }
  unsigned long max_factor = 1;
  for(pair<unsigned long, unsigned long> factor_pair : factors) {
    unsigned long factor = get<0>(factor_pair);
    unsigned long exp = get<1>(factor_pair);
    unsigned long mult = static_cast<unsigned long>(exp/n);
    unsigned long mult_factor = powl(factor, mult);
    if (exp >= n) {
      max_factor *= mult_factor;
    }
    //    printf("%lu %lu => %lu ^ %lu = %lu\n", factor, exp,
    //           factor, mult, mult_factor);
  }
  printf("%lu\n", max_factor);
  return 0;
}
