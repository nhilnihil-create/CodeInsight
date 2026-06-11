#include <iostream>
#include <map>
using namespace std;

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

#define DIVUP(x, y) (((x) + ((y) - 1)) / (y))
#define DIVOFF(x, y) (((x) + ((y) / 2)) / (y))
#define REMAINDER(x, y) ((x) % (y))

int main() {
  long N, P; scanf("%ld%ld", &N, &P);
  map<long, long> primes;

  while (P % 2 == 0) {
    ++primes[2];
    P /= 2;
  }
  for (long i{3}; i * i <= P; i += 2) {
    while (P % i == 0) {
      ++primes[i];
      P /= i;
    }
  }
  if (P > 1) {
    ++primes[P];
  }

  long factor{1};
  for (auto& prime : primes) {
    for (long i{1}; N * i <= prime.second; ++i) {
      factor *= prime.first;
    }
  }

  printf("%ld\n", factor);
  return 0;
}
