 #include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 10000007

int main()
{
    ll n;
    cin>>n;
    ll cost[n+1];
    ll dp[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>cost[i];

    }
    dp[n]=0;
   // dp[n-1]=abs(cost[n]-cost[n-1]);

    for(int i=n-1;i>0;i--)
    {
        if((i+2)<=n)
        {dp[i]=min((dp[i+1]+abs(cost[i+1]-cost[i])),(dp[i+2]+abs(cost[i+2]-cost[i])));}
        else
        {
            dp[i]=(dp[i+1]+abs(cost[i+1]-cost[i]));
        }
    }
    //
    cout<<dp[1]<<endl;
}