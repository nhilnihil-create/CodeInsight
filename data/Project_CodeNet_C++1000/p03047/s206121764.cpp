#include<stdio.h>

int main()
{
    int a[55];
    int n,k;
    for(int i = 0 ; i <= 55 ; i ++ )
    {
        a[i] = i;
    }
    scanf("%d%d",&n,&k);
    int sum = 0;
    int p = 1;
    int t = 0;
    while(p <= n)
    {
        p ++ ;
        t ++ ;
        if(t == k)
        {
            sum ++ ;
            t = 0;
            p = (p - k) + 1;
        }
    }
    printf("%d\n",sum);
    return 0;
}