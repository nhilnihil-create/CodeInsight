#include<stdio.h>
int main()
{
    int a,b,c,d,t;
    scanf("%d %d %d %d",&a,&b,&c,&d);

    if(a>b && c>d)
        t=b+d;
    else if(a>b && d>c)
        t=b+c;
    else if(b>a && c>d)
        t=a+d;
    else if(b>a && d>c)
        t=a+c;
        else if(a==b && c>d)
            t=a+d;

        else if(a==b && d>c)
            t=a+c;

        else if(c==d && a>b)
            t=b+c;
            else if(c==d && b>a)
            t=a+c;
        else if(c==d && a==b)
            t=a+c;
    printf("%d\n",t);
    return 0;
}
