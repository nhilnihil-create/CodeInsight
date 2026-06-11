#include <stdio.h>

int main (){
  char kata[255];
  int L, I;

  scanf("%d %d", &L, &I);
  scanf("%s", kata);
  kata[I-1] = kata[I-1] + 32;
  printf("%s", kata);
  return 0;
}



