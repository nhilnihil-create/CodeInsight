#include<stdio.h>
#include<math.h>

int main()
{
    int n,i;
    int arr1[60];
    int arr2[60];
    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",&arr1[i]);
     for(i=0;i<n;i++)
        scanf("%d",&arr2[i]);

    int output=0;

    for(i=0;i<n;i++)
    {
        if(arr1[i]>arr2[i])
            output=output+(arr1[i]-arr2[i]);

    }
    printf("%d",output);
}
