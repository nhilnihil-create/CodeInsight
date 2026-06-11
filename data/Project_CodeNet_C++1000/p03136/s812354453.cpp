#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

#define size 100005

int main()
{
    int n, i, arr[size], sum=0, max;
    scanf("%d", &n);
    max=0;

    for(i=1; i<=n; i++)
    {
        scanf("%d", &arr[i]);
        sum = sum + arr[i];
        if(arr[i]>max)
            max = arr[i];
    }

    if((sum-max)>max)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
