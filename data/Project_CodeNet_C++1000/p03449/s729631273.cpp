#include <bits/stdc++.h>
using namespace std;
int n,a[3][105],dp[3][105];
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=2;++i)
        for (int j=1;j<=n;++j) {
            int x;scanf("%d",&x);
            dp[i][j]=max(dp[i-1][j],dp[i][j-1])+x;
        }
    printf("%d\n",dp[2][n]);
    return 0;
}
