#include<stdio.h>
int main(void){
  int x,y;
  scanf("%d %d",&x,&y);
  if(x<=8 && y<=8){
    printf("Yay!");
  }else{
    printf(":(");
  }
  return 0;
}