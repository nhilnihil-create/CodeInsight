#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);

  int res = 0;
  while (n) {
    if (n % 10 == 2) ++res;
    n /= 10;
  }
  printf("%d\n", res);
}
