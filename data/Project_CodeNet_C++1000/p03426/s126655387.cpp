#include <bits/stdc++.h>///int * int = int
using namespace std;
int h,w,d,s[300][300],q,a,b;
int x[90001],y[90001];
int dp[90001];
int main()
{
    scanf("%d%d%d",&h,&w,&d);
    for(int i = 0;i < h;i ++)
    {
        for(int j = 0;j < w;j ++)
        {
            scanf("%d",&s[i][j]);
            x[s[i][j]] = i;
            y[s[i][j]] = j;
        }
    }
    for(int i = 1 + d;i <= h * w;i ++)
    {
        dp[i] = dp[i - d] + abs(x[i] - x[i - d]) + abs(y[i] - y[i - d]);
    }
    scanf("%d",&q);
    for(int i = 0;i < q;i ++)
    {
        scanf("%d%d",&a,&b);
        printf("%lld\n",abs(dp[a] - dp[b]));
    }
}