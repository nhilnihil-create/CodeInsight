#include <cstdio>

int main() {
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);

  printf("%d\n", (n + 1 - a) * (n + 1 - b));
  return 0;
}