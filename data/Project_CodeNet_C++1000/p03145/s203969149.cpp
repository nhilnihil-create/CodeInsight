#include <stdio.h>

int main (){
  int AB, BC, CA;
  int ABC;

  scanf("%d %d %d", &AB, &BC, &CA);
  ABC = 0.5*BC*AB;
  printf("%d\n", ABC);

    return 0;
}