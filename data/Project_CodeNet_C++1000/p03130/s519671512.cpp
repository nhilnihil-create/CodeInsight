#include <bits/stdc++.h>
typedef long long ll;
#define mod 1000000007
using namespace std;

vector<int>adj[5];
int visited[5];
int child[5];

void dfs(int node)
{
    visited[node]=1;

    for(int to : adj[node])
    {
        child[node]++;
        if(!visited[to])
            dfs(to);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0;i<3;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1;i<=4;i++)
        if(!visited[i])
        dfs(i);

    int flag=1;
    for(int i=1;i<=4;i++)
    {
        if(child[i]>2)
        {
            flag=0;
            break;
        }
    }

    if(flag)
        cout<<"YES";
    else
        cout<<"NO";

    return 0;
}
