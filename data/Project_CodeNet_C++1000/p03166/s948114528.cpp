#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl '\n'
const long long inf=1e18;
vector<ll>tree[100005];
ll dp[100005];
ll vis[100005];
void dfs(ll v)
{
    vis[v]=true;
    for(int child:tree[v])
    {
        if(!vis[child])
        {
            dfs(child);
        }
        dp[v]=max(dp[v],dp[child]+1);
    }
}
void testCase()
{
   // ll t; cin>>t; while(t--)
    {
        ll n,m;
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            ll x,y;
            cin>>x>>y;
            tree[x].push_back(y);
        }

        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                dfs(i);
            }
        }
        ll ans=0;
        for(int i=1;i<=n;i++)
        ans=max(ans,dp[i]);
        cout<<ans<<endl;
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