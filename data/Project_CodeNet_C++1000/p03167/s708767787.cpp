#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl '\n'
const long long inf=1e18;
#define mod 1000000007
char ar[1005][1005];
ll dp[1005][1005];


void testCase()
{
   // ll t; cin>>t; while(t--)
    {
        ll n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            cin>>ar[i][j];
        }

        dp[1][1]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(ar[i][j]=='#')
                {
                    dp[i][j]=0;
                    continue;
                }
                if(i>1)
                dp[i][j]+=dp[i-1][j];
                dp[i][j]%=mod;
                if(j>1)
                dp[i][j]+=dp[i][j-1];
                dp[i][j]%=mod;
            }
        }
        cout<<dp[n][m]<<endl;

    } 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    testCase();
    return 0;
}