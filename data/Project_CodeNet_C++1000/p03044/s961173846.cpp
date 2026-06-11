#include<bits/stdc++.h>
#define fastio  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define debug(x) cout << #x << "--> " << x << endl;
#define int long long
#define pii pair<int, int>
using namespace std;
const int mxn = 1e5 + 5;
vector<pii>graph[mxn];
int vis[mxn], color[mxn];
void bfs(int src)
{
    vis[src] = true;
    color[src] = 0;
    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
        int top = q.front();
        q.pop();
        for(int i = 0; i < graph[top].size(); i++)
        {
            pii node = graph[top][i];
            if(vis[node.first] == false)
            {
                vis[node.first] = true;
                color[node.first] = (node.second % 2) ? (1 ^ color[top]) : color[top];
                q.push(node.first);
            }
        }
    }
}
main()
{
    fastio;
    int n; cin >> n;
    for(int i = 0; i < n-1; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }
    memset(color, -1, sizeof color);
    bfs(1);
    for(int i = 1; i <= n; i++) cout << color[i] << endl;
}
