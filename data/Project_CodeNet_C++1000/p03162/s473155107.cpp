#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F first
#define S second
#define ii pair < int , int >
#define ever (;;)

const int N = 100100;

int n,a[N][3],dp[N][3];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=3;j++)
            scanf("%d",&a[i][j]);

    for(int i=n;i>=1;i--)
        for(int last=1;last<=3;last++)
            for(int j=1;j<=3;j++)
                if( j != last )
                    dp[i][last] = max( dp[i][last] , dp[i+1][j] + a[i][j] );

    printf("%d\n",max( { dp[1][1] , dp[1][2] , dp[1][3] } ) );
}
