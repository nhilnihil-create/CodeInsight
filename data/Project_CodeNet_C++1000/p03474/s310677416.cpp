#include <stdio.h>
 
int main() {
  int c, d, pos = 0;
  char str[20];
  scanf("%d %d %s", &c, &d, str);
  for (int i = 0; str[i] != '\0'; i++) {
    (str[i] == '-') ? pos += i + 1 : pos += 0;
  }
  pos == c + 1 ? puts("Yes") : puts("No");
  return 0;
}