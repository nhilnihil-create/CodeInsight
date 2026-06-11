#include <stdio.h>
int main(void)
{
  int R;
  scanf("%d\n",&R );

  if (R < 1200)
  {
    printf("ABC");
  }
  else if (R < 2800)
  {
    printf("ARC");
  }
  else
  {
    printf("AGC");
  }
  return 0;
}