#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[405][405],a[405],pref_cost[405];
const ll inf = 1e18+10;

int main()
{
    int n;
    cin >> n;
    
    for(int i=1;i<=n;++i)
    cin >> a[i];
    
    pref_cost[1]=a[1];
    for(int i=2;i<=n;++i)
    {
        pref_cost[i]+=pref_cost[i-1]+a[i];
    }
    
    for(int i=n;i>=0;--i)
    {
        for(int j=i;j<=n;++j)
        {
            dp[i][j]=inf;
            if(i==j)
            dp[i][j]=0;
            for(int k=i;k<j;++k)
            {
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+pref_cost[j]-pref_cost[i-1]);
            }
        }
    }
    cout << dp[1][n] << '\n';
    
    return 0;
}