#include <stdio.h>
 
int main(void){
  int a , b , takasa = 0;
  scanf("%d %d",&a ,&b);
  
  for(int i = 1;i < b-a;i ++){
    takasa += i;
  }
  
  printf("%d",takasa - a);
  
  return 0;
}