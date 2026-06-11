 #include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 10000007

int main()
{
    ll n,k;
    cin>>n;
    cin>>k;
    ll cost[n+1];
    ll dp[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>cost[i];

    }
    dp[n]=0;
     for(int i=n-1;i>0;i--)
    {
        dp[i]=INT_MAX ;
        for(int j=1;j<=k;j++)
        {    if(i+j<=n)
            {dp[i]=min(dp[i],(dp[i+j]+abs(cost[i+j]-cost[i])));
            }

        }
    }
    //
    cout<<dp[1]<<endl;
}



