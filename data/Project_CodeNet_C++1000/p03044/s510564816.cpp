#include <bits/stdc++.h>

using namespace std;
using Edge = pair<int,int>;
using Graph = vector<vector<Edge>>;

vector<int>result;
int N;
Graph G;

void dfs(int v, int c)
{
    result[v] = c;
    for(auto nx: G[v])
    {
        if(result[nx.first] != -1)
        {
            continue;
        }
        if(nx.second % 2 == 0)
        {
            dfs(nx.first, c);
        }
        if(nx.second % 2 == 1)
        {
            dfs(nx.first, 1-c);
        }
    }
}

int main()
{
    cin >> N;
    G.resize(N);
    for(int i = 0; i < N-1; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        u--;
        v--;
        G[u].push_back(Edge(v,w));
        G[v].push_back(Edge(u,w));
    }
    result.assign(N,-1);
    dfs(0,0);
    for(auto x: result)
    {
        cout << x << endl;
    }
    return 0;
}