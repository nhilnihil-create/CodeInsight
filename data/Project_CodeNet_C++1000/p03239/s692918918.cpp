#include<stdio.h>
int main(void){
  int n,t;
  int min=1001;
  scanf("%d %d",&n,&t);
  for(int i=0;i<n;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    if(b<=t && a<min){
      min=a;
    }
  }
  if(min>1000){
    printf("TLE\n");
  }else{
    printf("%d\n",min);
  }
  return 0;
}