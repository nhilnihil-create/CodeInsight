#include <cstdio>

int main()
{
    int a,sum=0;
    scanf("%d",&a);
    
    if(a%10 == 1)
    {
        sum = sum + 1;
    }
    if((a/10)%10 == 1)
    {
        sum = sum +1;
    }
    if(a/100)
    {
        sum = sum + 1;
    }
    printf("%d",sum);
}
