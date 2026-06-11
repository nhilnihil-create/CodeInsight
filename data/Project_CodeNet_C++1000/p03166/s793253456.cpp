#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin>>n>>m;
    vector<int> indegree(n+1), dis(n+1, 0);
    vector<vector<int>> g(n+1);
    
    for(int i = 0;i<m;i++)
    {
        int x, y;
        cin>>x>>y;
        indegree[y] += 1;
        g[x].push_back(y);
    }
    
    queue<int> q;
    for(int i = 1;i<=n;i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }
    int ans = 0;
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        
        for(int i = 0;i<g[x].size();i++)
        {
            dis[g[x][i]] = max(dis[g[x][i]], 1 + dis[x]);
            ans = max(dis[g[x][i]], ans);
            indegree[g[x][i]] -= 1;
            if(indegree[g[x][i]] == 0)
            {
                q.push(g[x][i]);
            }
        }
    }
    cout<<ans<<"\n";
}