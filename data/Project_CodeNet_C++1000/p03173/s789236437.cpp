#include<iostream>
#include<vector>
using namespace std;
using ll=long long ;
int main()
{
    int n;
    cin>>n;
    vector<ll> arr(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    ll dp[n+1][n+1];
    vector<ll> pref(n+1);
    for(int i=1;i<=n;i++)
    {
        pref[i]=pref[i-1]+arr[i];
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            dp[i][j]=10e16;
        }
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=i;j<=n;j++)
        {
            if(i==j)
            dp[i][j]=0;
            else
            {
                // dp[i][j]=;
                for(int k=i;k<j;k++)
                {
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+pref[j]-pref[i-1]);
                }
            }
        }
    }
    cout<<dp[1][n];

}