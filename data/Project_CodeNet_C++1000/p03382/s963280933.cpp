#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define MAX_N (100000)
#define INF (1000000000 + 1)

using namespace std;

int main(int argc, char *argv[]) {
  // read inputs
  int n, as[MAX_N];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &as[i]);
  }

  // sort
  sort(as, as + n);

  // solve
  const int i = n - 1, a_i = as[n - 1];
  const int k_max0 = a_i / 2, k_max1 = (a_i + 1) / 2;
  const int k_max2 = a_i - k_max0, k_max3 = a_i - k_max1;
  int d_max = INF, a_j_max = -1;
  for (int j = 0; j < n; j++) {
    const int a_j = as[j];
    const int d =
        min(abs(a_j - k_max0),
            min(abs(a_j - k_max1), min(abs(a_j - k_max2), abs(a_j - k_max3))));
    if (d < d_max) {
      a_j_max = a_j;
      d_max = d;
    }
  }
  printf("%d %d\n", a_i, a_j_max);

  return 0;
}
