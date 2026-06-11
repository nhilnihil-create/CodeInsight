#include <stdio.h>

int main()
{
    int n, i, sum=0, max;
    scanf("%d", &n);
    int arr[n+5];
    
    scanf("%d", &arr[1]);
    max = arr[1];
    sum = arr[1];
    for(i=2; i<=n; i++)
    {
        scanf("%d", &arr[i]);
        sum = sum + arr[i];
        if(arr[i]>max)
        max = arr[i];
    }
    printf("%d", sum-max/2);
    return 0;
}
