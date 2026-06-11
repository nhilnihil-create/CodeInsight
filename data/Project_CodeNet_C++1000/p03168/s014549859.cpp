#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F first
#define S second
#define ii pair < int , int >
#define ever (;;)

const int N = 3010;

int n;
double dp[N][N],p[N];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lf",&p[i]);

    for(int i=(n+1)/2;i<=n;i++)
        dp[n+1][i] = 1.0;

    for(int i=n;i>=1;i--)
        for(int j=0;j<=n;j++)
            dp[i][j] = p[i]*dp[i+1][j+1] + (1.0-p[i])*dp[i+1][j];

    printf("%.9f\n",dp[1][0]);
}
