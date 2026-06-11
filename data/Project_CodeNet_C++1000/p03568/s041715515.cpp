#include<stdio.h>
int main(void){
  int n,a[10];
  scanf("%d",&n);
  int all=1,bad=1;
  for(int loop=0;loop<n;++loop){
    scanf("%d",a+loop);
    all*=3;
    if(a[loop]%2==0){
      bad*=2;
    }
  }
  printf("%d",all-bad);
  return 0;
}