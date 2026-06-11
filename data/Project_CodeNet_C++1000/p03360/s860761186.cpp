#include <stdio.h>
int main(){
  int a, b, c, k, maior, soma;
  scanf("%d %d %d %d", &a, &b, &c, &k);
  maior=a;

  if(b>maior)
    maior=b;

  if(c>maior)
    maior=c;

  soma=a+b+c-maior;

  while(k--)
    maior=maior*2;

    printf("%d\n", soma+maior);

  return 0;
}
