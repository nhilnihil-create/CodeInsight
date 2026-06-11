#include <stdio.h>
int main(void)
{
  int R;
  scanf("%d\n",&R );

  if (R%2 == 0)
  {
    printf("%d\n",R );
  }
  else
  {
    printf("%d\n",R*2 );
  }
  return 0;
}