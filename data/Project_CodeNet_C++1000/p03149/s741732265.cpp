#include<stdio.h>

int main(void){
  int N[4],i,j,f,A[4]={1,9,7,4};
  scanf("%d %d %d %d",&N[0],&N[1],&N[2],&N[3]);
  f = 0;
  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      if(N[i]==A[j]){A[j]=99;f++;break;}
    }
  }
  if(f==4){printf("YES\n");}else{printf("NO\n");}
  return 0;
}