#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>a(n+1) , b(n+1) , c(n+1);
    for(int i=1 ; i<=n ; i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    int dp[n+1][4];
    dp[1][1] = a[1];
    dp[1][2] = b[1];
    dp[1][3] = c[1];

    for(int i=2 ; i<=n ; i++)
    {
        for(int j=1 ; j<=3 ; j++)
        {
            if(j==1)
            {
                dp[i][j] = a[i] + max(dp[i-1][2] , dp[i-1][3]);
            }
            else if(j==2)
            {
                dp[i][j] = b[i] + max(dp[i-1][1] , dp[i-1][3]);
            }
            else if(j==3)
            {
                dp[i][j] = c[i] + max(dp[i-1][1] , dp[i-1][2]);
            }
        }
    }
    int ans = max(dp[n][1] , dp[n][2]);
    ans = max(ans , dp[n][3]);
    cout<<ans<<endl;

}
