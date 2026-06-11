#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define mod 1000000007

const int sz=1e5+5;
ll inf=1e15;

ll dp[sz][2],n;
vector<int> ar[sz];

void dfs(int u,int pr)
{
    dp[u][0]=1;
    dp[u][1]=1;
    for(int v:ar[u])
    {
        if(v!=pr)
        {
            dfs(v,u);
            dp[u][0]=((dp[u][0]*dp[v][0])%mod+(dp[u][0]*dp[v][1])%mod)%mod;
            dp[u][1]=((dp[u][1]*dp[v][0])%mod);
        }
    }
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        cin>>n;

        for(int i=0;i<n-1;i++)
        {
            int u,v;
            cin>>u>>v;
            ar[u].push_back(v);
            ar[v].push_back(u);
        }

        dfs(1,0);

        cout<<(dp[1][0]%mod+dp[1][1]%mod)%mod;

        
    }

    return 0;
}