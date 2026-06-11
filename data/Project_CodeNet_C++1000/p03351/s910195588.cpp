#include<stdio.h>

int main()
{
    int a , b, c, d,x,y,z;

    scanf("%d %d %d %d", &a, &b, &c, &d);

    if(a > c)
        z = a - c;
    else
        z = c - a;
    if(a > b)
       x = a - b;
    else
        x = b - a;
    if(b > c)
        y = (b - c);
    else
        y = c - b;


    if(z <= d || (x <= d && y<= d))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}