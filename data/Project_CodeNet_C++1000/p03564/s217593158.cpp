#include <stdio.h>

int main() {
  int n, k, sum = 1;
  scanf("%d %d", &n, &k);

  for(int i = 0; i < n; i++) {
    int sum1 = sum * 2;
    int sum2 = sum + k;
    if(sum1 < sum2) {
      sum *= 2;
    }
    else {
      sum += k;
    }
  }
  printf("%d", sum);
  return 0;
}