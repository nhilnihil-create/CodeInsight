#include <stdio.h>

int main(void) {
  int i, j, k, n;
  scanf("%d", &n);
  if(n == 3) {
    printf("2 3 25");
  } else {
    int now = 9;
    printf("2 4 3 9");
    if(n & 1) {
      printf(" 6");
      for(i = 5; i < n; ++i) {
        if(now % 6 == 3 || !(now % 6)) now += 6;
        else if(now % 6 == 2) now += 2;
        else now += 4;
        if(now > 30000) {
          if(now % 6 == 3) now = 8;
          else now = 12;
        }
        printf(" %d", now);
      }
    } else {
      for(i = 4; i < n; ++i) {
        if(now % 6 == 3 || !(now % 6)) now += 6;
        else if(now % 6 == 2) now += 2;
        else now += 4;
        if(now > 30000) {
          if(now % 6 == 3) now = 8;
          else now = 6;
        }
        printf(" %d", now);
      }
    }
  }
  return 0;
}