#include<stdio.h>
int main(void)
{
  int h1,h2,w1,w2;
  
  scanf("%d%d%d%d",&h1,&w1,&h2,&w2);
  printf("%d",(h1-h2)*(w1-w2));
  return 0;
}