#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>
#define LL long long
using namespace std;
int main()
{
    LL a[200001],sum=0;
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%lld",&a[i]);
    for(i=0;i<n;i++)
    {
        if(a[i]>i||i>0&&(a[i]-1>a[i-1]))
        {
            printf("-1\n");
            return 0;
        }
        if(a[i]-1==a[i-1]&&i>0)
            sum++;
        else
            sum+=a[i];
    }
    printf("%lld\n",sum);

    return 0;
}