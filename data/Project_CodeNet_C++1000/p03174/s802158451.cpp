#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F first
#define S second
#define ii pair < int , int >
#define ever (;;)

const int N = 23;

int n,a[N][N],dp[N][1<<N],mod=1e9+7;
vector <int> v[N];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    for(int i=0;i<(1<<n);i++)
    {
        dp[n][i] = 1;
        v[__builtin_popcount(i)].push_back(i);
    }

    for(int i=n-1;i>=0;i--)
        for(auto j:v[i])
            for(int k=0;k<n;k++)
                if( !(j&(1<<k)) && a[i][k] )
                    dp[i][j] = ( dp[i+1][j|(1<<k)] + dp[i][j] )%mod;

    printf("%d\n",dp[0][0]);
}
