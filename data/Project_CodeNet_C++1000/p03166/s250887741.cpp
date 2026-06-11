#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
int vis[1000000];
int D[1000000];

void dfs(int node)
{
        if(vis[node])
                return;
        vis[node] = 1;
        for(auto j : g[node])
        {
                dfs(j);
                D[node] = max(D[node], D[j] + 1);
        }
}

int main()
{
        int i;
        cin >> n >> m;
        g.resize(n + 1);
        for(i = 0; i < m; i++)
        {
                int u, v;
                cin >> u >> v;
                g[u].push_back(v);
        }
        for(i = 1; i <= n; i++)
        {                                   // make directed edge from 0 to every other vertex 
                g[0].push_back(i);
        }
        dfs(0);
       
        cout << D[0] - 1 << endl;

}
