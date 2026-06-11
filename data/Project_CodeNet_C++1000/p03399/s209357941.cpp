#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a,b,c,d,x,y;
    while(~scanf("%d",&a))
    {
        scanf("%d",&b);
        scanf("%d",&c);
        scanf("%d",&d);
        if(a>b)
            x=b;
        else
            x=a;
        if(c>d)
            y=d;
        else
            y=c;
        printf("%d\n",x+y);
    }
    return 0;
}
