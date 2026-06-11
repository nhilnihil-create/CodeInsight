#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F first
#define S second
#define ii pair < int , int >
#define ever (;;)

const int N = 1010;

int n,m,dp[N][N],mod=1e9+7;
char a[N][N],A[N][N];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",&A[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            a[i][j] = A[i-1][j-1];

    dp[n][m] = 1;
    for(int i=n;i>=1;i--)
        for(int j=m;j>=1;j--)
        {
            if( a[i][j] == '#' || ( i == n && j == m ) )
                continue;

            if( i != n && a[i+1][j] == '.' )
                dp[i][j] += dp[i+1][j];
            if( j != m && a[i][j+1] == '.' )
                dp[i][j] += dp[i][j+1];

            dp[i][j] %= mod;
        }

    printf("%d\n",dp[1][1]);
}
