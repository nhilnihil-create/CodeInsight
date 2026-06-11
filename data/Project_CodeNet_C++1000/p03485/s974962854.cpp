#include <cstdio>

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    
    if((a+b)%2 == 0)
    {
        printf("%d",(a+b)/2);
    }
    else if((a+b)%2 != 0)
    {
        printf("%d",((a+b)/2)+1);
    }
}