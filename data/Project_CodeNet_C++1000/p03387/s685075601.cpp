#include <stdio.h>
int main(){
  int a,b,c;
  scanf("%d%d%d",&a,&b,&c);
  int ans = 0;
  while(!(a==b && b==c) || ans%2==1){
    ans += 1;
    if(a<=b && a<=c){
      a += 1;
    }else if(b<=a && b<=c){
      b += 1;
    }else{
      c += 1;
    }
  }
  ans /= 2;
  printf("%d\n",ans);
  return 0;
}
