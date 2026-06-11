#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F first
#define S second
#define ii pair < int , int >
#define ever (;;)

const int N = 110;

int n,k,a[N],dp[N][100100],cum[100100],mod=1e9+7;

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);

    dp[n+1][0] = 1;

    for(int i=0;i<=k;i++)
        cum[i] = 1;

    for(int i=n;i>=1;i--)
    {
        for(int j=0;j<=k;j++)
            dp[i][j] = ( ( cum[j] - cum[max(j-a[i]-1,0)] + ( ( j-a[i]-1<0 ) ? cum[0] : 0 ) ) %mod + mod ) %mod;

        cum[0] = dp[i][0];
        for(int j=1;j<=k;j++)
            cum[j] = ( cum[j-1] + dp[i][j] )%mod;
    }

    printf("%d\n",dp[1][k]);
}
