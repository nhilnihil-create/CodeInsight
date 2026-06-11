#include<iostream>
#include<map>
#include<list>
#include<cstring>
using namespace std;
map<int,list<int>>mp;
int dp[100005];
int solve(int src)
{
    if(dp[src]!=-1)
    {
        return dp[src];
    }
    bool node=0;
    int newnode=0;
    for(auto i:mp[src])
    {
        node=1;
        newnode=max(newnode,1+solve(i));
    }
    if(node==0)
    {
        return dp[src]=0;
    }
    else{
        return dp[src]=newnode;
    }
}
int main()
{
    int n,m,k,ans=0;
    cin>>n>>m;
    k=m;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b);
    }
        memset(dp,-1,sizeof dp);
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,solve(i));
        }
        cout<<ans<<endl;
    }
