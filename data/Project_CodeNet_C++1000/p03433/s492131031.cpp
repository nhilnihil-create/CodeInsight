#include <stdio.h>
int main()
{
  int N,X,Z;
  scanf("%d%d",&N,&X);
  Z=(N%500);
  if(Z==0)
  {
    printf("Yes\n");
  }
  else if(Z<=X)
  {
    printf("Yes\n");
  }
  else
  {
  printf("No\n");
  
  }
  return 0;
  }
   
    
   