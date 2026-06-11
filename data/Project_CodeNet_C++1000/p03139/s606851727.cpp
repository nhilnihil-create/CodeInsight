#include<stdio.h>

int main(void)
{
  int N,A,B,max,min;
  scanf("%d%d%d",&N,&A,&B);
  
  if(A>B){
    max=B;
  }else{
    max=A;
  }
  
  if(A+B-N>0){
    min=A+B-N;
  }else{
    min=0;
  }
  
  printf("%d %d",max,min);
  
  return 0;
}