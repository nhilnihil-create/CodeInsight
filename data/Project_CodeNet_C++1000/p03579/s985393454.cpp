#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

using namespace std;
#define prev prev55

long long n, m;
vector<int> g[500000];

int color[500000];
int bipartite = 1;
int c[3];

void dfs(int v, int fl)
{
    color[v] = fl;
    c[fl]++;
    for (auto u : g[v])
    {
        if (color[u] == fl) bipartite = 0;
        else if (color[u] == 0) dfs(u, 3 - fl);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 1);
    if (bipartite)
    {
        cout << 1LL * c[1] * c[2] - m;
    }
    else
    {
        cout << n * (n - 1) / 2 - m;
    }
}
