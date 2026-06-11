#include <stdio.h>
#include <string.h>

int main() {
  int a, b, flag = 0;
  scanf("%d %d", &a, &b);

  char num[a + b + 2];
  scanf("%s", num);

  int len = strlen(num);
  for(int i = 0; i < len; i++) {
    if((num[i] == '-' && i != a) || num[a] != '-') {
      flag = 1;
      break;
    }
  }

  if(!flag) printf("Yes");
  else printf("No");
  return 0;
}