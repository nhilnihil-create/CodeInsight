#include<stdio.h>

int main(void)
{
  int N,i,S;
  char A[100],B[100],C[100];
  scanf("%d\n%s\n%s\n%s",&N,&A,&B,&C);
  
  S=0;
  for(i=0;i<=N-1;i++){
    if(A[i]==B[i]){
      if(B[i]!=C[i]){
        S++;
      }
    }else if(A[i]==C[i]){
      S++;
    }else if(B[i]==C[i]){
      S++;
    }else{
      S=S+2;
    }
  }
  
  printf("%d",S);
  
  return 0;
}