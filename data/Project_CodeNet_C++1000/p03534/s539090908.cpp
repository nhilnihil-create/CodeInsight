#include <stdio.h>
#include <string.h>

int min(int a, int b) {
  return a < b ? a : b;
}

int main(void) {
  int i, c[3] = {0, 0, 0};
  char s[100010];
  scanf("%s", s);
  for(i = 0; i < strlen(s); ++i) c[s[i] - 'a']++;
  int t = min(c[0], min(c[1], c[2]));
  c[0] -= t, c[1] -= t, c[2] -= t;
  for(i = 0; i < 3; ++i) if(c[i] > 1) {
    printf("NO");
    return 0;
  }
  printf("YES");
  return 0;
}