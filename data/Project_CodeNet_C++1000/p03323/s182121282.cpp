#include <stdio.h>
int main(){
  int a, b;
  scanf("%d %d", &a, &b);

  if((a+b)>16 || b>8 || a>8)
    printf(":(\n");
  else
    printf("Yay!\n");

  return 0;
}
