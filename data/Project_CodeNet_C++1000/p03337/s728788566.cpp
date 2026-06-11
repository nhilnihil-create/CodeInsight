#include <stdio.h>
int main(){
  int a, b, resp;
  scanf("%d %d", &a, &b);
  resp=a+b;

  if((a-b)>resp)
    resp=a-b;

  if((a*b)>resp)
    resp=a*b;

  printf("%d\n", resp);
    
  return 0;
}
