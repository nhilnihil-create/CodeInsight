// In the Name of Allah. Ya Ali!
#include<bits/stdc++.h>
#define bp __builtin_popcount
typedef long long ll;
const ll MAX_N = 300+5;
const ll MOD = 1e9+7;
using namespace std;

int dp[MAX_N][MAX_N][MAX_N];
int a[MAX_N];
int n,k;

int main()
{
    string s;
    cin >> s >> k;
    n = s.length();
    for(int i = 1;i<=n;++i)
        a[i] = (s[i-1]-'a');
    for(int i = 1;i<=n;++i)
        for(int j = 0;j<=n;++j)
            dp[1][i][j] = 1;
    for(int i = 2;i<=n;++i)
    {
        for(int j = 1;j<=n-i+1;++j)
        {
            for(int t = 0;t<=n;++t)
            {
                dp[i][j][t] = max(dp[i-1][j][t],dp[i-1][j+1][t]);
                if (t-(a[j]!=a[j+i-1])>=0)
                    dp[i][j][t] = max(dp[i][j][t],dp[i-2][j+1][t-(a[j]!=a[j+i-1])]+2);
            }
        }
    }
    cout << dp[n][1][k];
    return 0;
}
