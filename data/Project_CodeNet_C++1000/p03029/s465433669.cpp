#include <stdio.h>

int main() {
  int A, P;
  scanf("%d %d", &A, &P);

  int ApplePie = A*3 + P;
  if(ApplePie % 2 == 0) {
    printf("%d", ApplePie / 2);
  }
  else if(ApplePie < 2) {
    printf("0");
  }
  else {
    printf("%d", (ApplePie - 1) / 2);
  }
  return 0;
}