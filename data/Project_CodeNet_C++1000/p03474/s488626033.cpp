#include <stdio.h>
 
int main() {
  int X, Y, pos = 0;
  char S[20];
  scanf("%d %d %s", &X, &Y, S);
  for (int i = 0; S[i] != '\0'; i++) {
    (S[i] == '-') ? pos += i + 1 : pos += 0;
  }
  pos == X + 1 ? printf("Yes") : printf("No");
  return 0;
}
