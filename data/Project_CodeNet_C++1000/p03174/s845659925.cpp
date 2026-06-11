#include <iostream>
using namespace std;
typedef long long int ll;
ll const mod = 1000000007;
ll dp[1<<22];
ll n;
ll map1[50][50];
int main()
{
    scanf("%lld",&n);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <=n ; j++)
        {
            scanf("%lld",&map1[i][j]);
        }
    }
    dp[0] = 1;
    for(int i = 1; i < (1<<n); i++)
    {
        int now = __builtin_popcount(i);
        for(int k = 1; k <= n; k++)
        {
            if((i>>(k-1)&1)&&map1[now][k])
            {
                dp[i]+= dp[i^(1<<(k-1))];
                dp[i]%=mod;
            }
        }
    }

    printf("%lld\n",dp[(1<<n)-1]);
}
