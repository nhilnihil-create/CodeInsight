#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#define ll long long
using namespace std;
ll a[200006];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++)
            scanf("%lld",&a[i]);
        int r=0;
        ll sum1=0,sum2=0,sum=0;
        for(int i=0;i<n;i++)
        {
            while((sum1^a[r])==(a[r]+sum2)&&r<n)
            {
                sum1^=a[r];
                sum2+=a[r++];
            }
            sum+=(r-i);
            sum1^=a[i];
            sum2-=a[i];
        }
        printf("%lld\n",sum);
    }
    return 0;
}