#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main()
{
    int n,i;
    scanf("%d",&n);
    lli a[n];
    for(i=0;i<n;i++)
    scanf("%lld",&a[i]);
    lli ans[n]={0};
    ans[n-1]=0;
    ans[n-2]=abs(a[n-2]-a[n-1]);
    for(i=n-3;i>=0;i--)
    ans[i]=min(ans[i+1]+abs(a[i]-a[i+1]),ans[i+2]+abs(a[i]-a[i+2]));
    printf("%lld",ans[0]);
}