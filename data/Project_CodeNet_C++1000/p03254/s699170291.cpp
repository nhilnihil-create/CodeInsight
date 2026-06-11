#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

#define size 100005

int main()
{
    long long int n, ttl, i, j, temp, arr[size], h=0;
    scanf("%lld%lld", &n, &ttl);

    for(i=1; i<=n; i++)
        scanf("%lld", &arr[i]);
    
    for(i=1; i<=n; i++)
    {
        for(j=i; j<=n; j++)
        {
            if(arr[i]>arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for(i=1; i<n; i++)
    {
        if((ttl-arr[i])>=0)
        {
            h++;
            ttl -= arr[i];
        }
    }
    if(ttl==arr[n])
        h++;
    printf("%d", h);

    return 0;
}