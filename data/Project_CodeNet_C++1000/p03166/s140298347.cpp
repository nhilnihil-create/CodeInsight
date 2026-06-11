#include<iostream>
#include<vector>
#define ll long long
#define MOD 1000000007
using namespace std;
int dfs(int *dp,vector<vector<int>>& adj,int n,int i)
{
    if(dp[i]!=-1)
        return dp[i];
    int res=0;
    for(int g=0;g<adj[i].size();g++)
    {
        res=max(res,1+dfs(dp,adj,n,adj[i][g]));
    }
    dp[i]=res;
    return res;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    int *dp=new int[n+1]();
    for(int i=0;i<=n;i++)
        dp[i]=-1;
    int myres=INT_MIN;
    for(int i=1;i<=n;i++)
    {
        myres=max(myres,dfs(dp,adj,n,i));
    }
    cout<<myres<<endl;
}
