#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector <long long> adj[1000005];
long long F[1000005], a, b, n, m, dd[1000005], res;
long long dfs(long long u)
{
    for (long long v : adj[u])
        if (!dd[v])
        {
            dd[v] = 1;
            F[u] = max(F[u], dfs(v) + 1);
        }
        else F[u] = max(F[u], F[v] + 1);
    return F[u];
}

int main()
{
    //freopen("LONGEST.INP", "r", stdin);
    cin >> n >> m;
    for (long long i = 1; i <= m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (long long i = 1; i <= n; i++)
        if (!dd[i])
        {
            dd[i] = 1;
            dfs(i);
        }

    for (long long i = 1; i <= n; i++) res = max(res, F[i]);
    cout << res;
    return 0;
}
