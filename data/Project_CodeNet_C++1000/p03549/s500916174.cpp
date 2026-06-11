#include<stdio.h>
int main(void){
  int n,m;
  scanf("%d %d",&n,&m);
  int ans=(n-m)*100+1900*m;
  while(m>0){
    m--;
    ans*=2;
  }
  printf("%d\n",ans);
  return 0;
}