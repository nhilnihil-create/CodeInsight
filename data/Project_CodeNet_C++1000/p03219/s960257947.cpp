#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m;
    while(~scanf("%d %d",&n,&m))
    {
        m=m/2;
        printf("%d\n",n+m);
    }
    return 0;
}
