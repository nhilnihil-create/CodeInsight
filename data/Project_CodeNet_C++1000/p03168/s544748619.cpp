#include<bits/stdc++.h>
#include <iomanip>
using namespace std;






int main()
{
    cout<<setprecision(9);
    int n;
    cin>>n;
    double dp[n+1][n+1];
    //memset(dp, 0.0, sizeof(dp));
    for(int i=0; i<=n; ++i)
    {
        for(int j=0; j<=n; ++j)
        {
            dp[i][j] = 0.0;
        }
    }

    double arr[n+1];
    arr[0] = 0;
    for(int i=1; i<=n; ++i)
    {
        cin>>arr[i];
    }
    dp[0][0] = 1.0;
    for(int i=1; i<=n; ++i)
    {
        for(int j=0; j<=i; ++j)
        {
            if(j == 0)
            {
                dp[i][j] = (1.0 - arr[i])*dp[i-1][j];
                continue;
            }
            else
            {
                dp[i][j] = (1.0 - arr[i])*dp[i-1][j] + dp[i-1][j-1]*arr[i];
            }
        }
    }





   /* for(int i=0; i<=n; ++i)
    {
        for(int j=0; j<=n; ++j)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/










    double ans = 0;

    for(int i=n; i>n/2; --i)
    {
        ans+=dp[n][i];
    }

    cout<<ans<<endl;
    return 0;

}
