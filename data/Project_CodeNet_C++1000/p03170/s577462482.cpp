#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define mod 1000000007

const int sz=1e5+5;
ll inf=1e15;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ll ar[n+1];
        for(int i=1;i<=n;i++)
        {
            cin>>ar[i];
        }
        bool dp[k+1];
        memset(dp,false,sizeof(dp));
        for(int i=1;i<=n;i++)
            dp[ar[i]]=true;
        for(int i=1;i<=k;i++)
        {
            for(int j=n;j>=1;j--)
            {
                if(i-ar[j]>=0)
                {
                    if(dp[i-ar[j]]==false)
                        dp[i]=true;
                }
            }
            // cout<<dp[i]<<" ";
        }
        if(dp[k])
        {
            cout<<"First"<<endl;
        }
        else
        {
            cout<<"Second"<<endl;
        }
    }

    return 0;
}