#include <stdio.h>
int main(void)
{
  int N;
  scanf("%d",&N);
  if(N==1)puts("Hello World");
  else{
    int A, B;
    scanf("%d %d",&A,&B);
    printf("%d\n",A+B);
  }

  return 0;
}