#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define INF 1000000000
int main()
{
    int n,k,i,j;
    scanf("%d %d",&n,&k);
    lli a[n];
    for(i=0;i<n;i++)
    scanf("%lld",&a[i]);
    lli ans[n];
    ans[n-1]=0;
    for(i=n-2;i>=0;i--)
    {
        ans[i]=INF;
        for(j=1;j<=k;j++)
        {
            if(i+j<n)
            ans[i]=min(ans[i],ans[i+j]+abs(a[i+j]-a[i]));
        }
    }
    printf("%lld",ans[0]);
}