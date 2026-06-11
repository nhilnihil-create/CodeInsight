#include<stdio.h>
int main(void){
  int d;
  scanf("%d",&d);
  if(d==25) printf("Christmas");
  else if(d==24) printf("Christmas Eve");
  else if(d==23) printf("Christmas Eve Eve");
  else printf("Christmas Eve Eve Eve");
  return 0;
}