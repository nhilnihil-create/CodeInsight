#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main()
{
    int n,a,b,c,i;
    scanf("%d",&n);
    scanf("%d %d %d",&a,&b,&c);
    lli ans[n][3],an;
    ans[0][0]=a;ans[0][1]=b;ans[0][2]=c;
    for(i=1;i<n;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        ans[i][0]=max(ans[i-1][1]+a,ans[i-1][2]+a);
        ans[i][1]=max(ans[i-1][0]+b,ans[i-1][2]+b);
        ans[i][2]=max(ans[i-1][0]+c,ans[i-1][1]+c);
    }
    an=ans[n-1][0];
    if(ans[n-1][1]>an)
    an=ans[n-1][1];
    if(ans[n-1][2]>an)
    an=ans[n-1][2];
    printf("%lld",an);
}