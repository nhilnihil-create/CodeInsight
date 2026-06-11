#include <iostream>
using namespace std;

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

#define DIVUP(x, y) (((x) + ((y) - 1)) / (y))
#define DIVOFF(x, y) (((x) + ((y) / 2)) / (y))
#define REMAINDER(x, y) ((x) % (y))

int main() {
  long N, P; scanf("%ld%ld", &N, &P);
  long factor{1};

  if (N == 1) {
    printf("%ld\n", P);
    return 0;
  }

  int count{};
  while (P % 2 == 0) {
    if (++count % N == 0) {
      factor *= 2;
    }
    P /= 2;
  }
  for (long i{3}; i * i <= P; i += 2) {
    count = 0;
    while (P % i == 0) {
      if (++count % N == 0) {
        factor *= i;
      }
      P /= i;
    }
  }

  printf("%ld\n", factor);
  return 0;
}
