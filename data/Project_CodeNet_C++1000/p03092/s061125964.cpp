// In the name of Allah. Ya ali!
#include<bits/stdc++.h>
#define double long double
typedef long long ll;
const ll MAX_N = 5000+10;
const ll MOD = 1e9+7;
using namespace std;

int a[MAX_N];
int pos[MAX_N];
ll dp[MAX_N][MAX_N];
int d[MAX_N][MAX_N];
int cnt[MAX_N][MAX_N];
ll n,l,r;

int main()
{
    cin >> n >> r >> l;
    for(int i = 1;i<=n;++i)
        cin >> a[i],pos[a[i]] = i;
    for(int i = n;i>=1;--i)
        for(int j = pos[i];j<=n;++j)
            d[j][i] = pos[i];
    for(int i = 1;i<=n;++i)
    {
        for(int j = 1;j<=n;++j)
        {
            cnt[i][j] = cnt[i-1][j] + (a[i]<=j);
        }
    }
    for(int i = 1;i<=n;++i)
    {
        for(int j = 1;j<=n;++j)
        {
            if (!d[i][j])
            {
                dp[i][j] = dp[i][j-1];
                continue;
            }
            if (d[i][j]==i)
            {
                dp[i][j] = dp[i-1][j];
                continue;
            }
            int t = cnt[i][j]-cnt[d[i][j]][j];
            dp[i][j] = min(dp[i][j-1]+r,dp[d[i][j]][j-1]+l*t);
        }
    }
    cout << dp[n][n];
    return 0;
}
