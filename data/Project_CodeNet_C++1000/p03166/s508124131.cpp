#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000005];
int dp[1000005];
bool visited[1000005];
void visit(int vertex)
{
    visited[vertex]=1;
    dp[vertex]=0;
    for(int child: adj[vertex])
    {
        if(!visited[child])
        visit(child);
        
        dp[vertex]=max(dp[vertex],dp[child]+1);
    }
}

int main()
{
    int x,y,a,b;
    cin>>x>>y;
    for(int i=0;i<y;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
    }

for(int i=1;i<=x;i++)
{
    if(!visited[i])
    visit(i);
}
int ans=0;
for(int i=1;i<=x;i++)
ans=max(ans,dp[i]);
cout<<ans;

    return 0;
}
