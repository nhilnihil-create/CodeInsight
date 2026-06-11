#include <bits/stdc++.h>

using namespace std;

const int MaxN = 100005;

int n, m;
vector<int> adj[MaxN];
int Pd[MaxN], Count[MaxN];
queue<int> q;

void BFS(int x)
{
    Pd[x] = 0;
    q.push(x);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
        {
            Count[v]--;
            if (Count[v] == 0)
            {
                q.push(v);
                Pd[v] = u;
            }
        }
        
    }
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int u, v;
    for (int i = n+m-1; i > 0; i--)
    {
        cin >> u >> v;
        Count[v]++;
        adj[u].push_back(v);
    }
    int Root = -1;
    for (int i = 1; i <= n; i++)
    {
        if (Count[i] == 0)
        {
            Root = i;
            break;
        }
    }
    BFS(Root);
    for (int i = 1; i <= n; i++)
    {
        cout << Pd[i] << '\n';
    }
    
    return 0;
}
