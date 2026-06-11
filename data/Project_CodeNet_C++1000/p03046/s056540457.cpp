#include <bits/stdc++.h>

using namespace std;

int main() {
  int m, k;
  scanf("%d %d", &m, &k);
  if (k == 0) {
    for (int i = 0; i < (1 << m); ++i)
      printf("%d %d ", i, i);
    return 0;
  }
  if (k >= (1 << m) || (m == 1 && k == 1)) {
    puts("-1");
    return 0;
  }
  printf("0 %d 0 ", k);
  for (int i = 1; i < (1 << m); ++i) {
    if (i != k)
      printf("%d ", i);
  }
  printf("%d ", k);
  for (int i = (1 << m) - 1; i >= 1; i--) {
    if (i != k)
      printf("%d ", i);
  }
  return 0;
}
