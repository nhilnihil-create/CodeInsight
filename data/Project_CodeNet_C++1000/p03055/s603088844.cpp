#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N = 2e5 + 4;
const int inf = 1e9;
vector<int> g[N];
int dis[N], n;

int bfs(int s)
{
    int i, u;
    for (i = 1; i <= n; i++)
        dis[i] = inf;

    dis[s] = 0;
    queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        u = q.front();
        s = u;
        q.pop();
        for (int v : g[u])
        {
            if (dis[v] == inf)
                dis[v] = 1 + dis[u], q.push(v);
        }
    }

    return s;
}

int main()
{
    int i, u, v;
    cin >> n;
    for (i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    u = bfs(1);
    v = bfs(u);

    if (dis[v] % 3 == 1)
        cout << "Second";
    else
        cout << "First";

    return 0;
}