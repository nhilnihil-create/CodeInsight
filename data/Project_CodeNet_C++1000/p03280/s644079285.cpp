#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    while(~scanf("%d%d",&a,&b))
    {
         printf("%d\n",(a-1)*(b-1));
    }
    return 0;
}
