#include<stdio.h>
int main(void){
  char a[11];
  scanf("%s",a);
  if((a[5]=='0') && (a[6]<'5')){
    printf("Heisei\n");
  }else{
    printf("TBD\n");
  }
  return 0;
}