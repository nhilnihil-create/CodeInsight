#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

#define size 100005

int main()
{
    int n, m, x, arr[size], tol[size], pos, i, a=0, b=0, min;
    scanf("%d%d%d", &n, &m, &x);

    for(i=0; i<=n; i++)
        tol[i]=0;

    for(i=1; i<=m; i++)
    {
        scanf("%d", &arr[i]);
        pos = arr[i];
        tol[pos]=1;
    }

    for(i=x+1; i<=n-1; i++)
    {
        if(tol[i]==1)
            a++;
    }
    for(i=x-1; i>=1; i--)
    {
        if(tol[i]==1)
            b++;
    }
    min = a<b ? a : b;
    printf("%d\n", min);

    return 0;
}
