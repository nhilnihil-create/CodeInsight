#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a,b,c;
    while(~scanf("%d %d",&a,&b))
    {
        c=b/2;
        printf("%d\n",a+c);
    }
    return 0;
}

