#include<stdio.h>
int main()
{
    int n,i,a[100000];
    scanf("%d",&n);
    for(i = 0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int temp;
    for(i = 0;i<n;i++)
    {
        for(int j = i+1;j<n;j++)
        {
            if(a[i]>=a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    int sum = 0;
    for(i = 0;i<n-1;i++)
    {
        sum += a[i];
    }
    if(sum <= a[n-1])
        printf("No\n");
    else
        printf("Yes\n");

}
