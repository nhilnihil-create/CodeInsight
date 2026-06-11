#include <stdio.h>
int main()
{
    int n,i,ttl=0,high=0,ttl2,x;
    scanf("%d",&n);
    for(x=1;x<=n;x++)
    {
        scanf("%d",&i);
        if(i>high)
        {
            high=i;
        }
        ttl=i+ttl;
    }
    ttl2=ttl-(high/2);
    printf("%d",ttl2);
    return 0;
}
