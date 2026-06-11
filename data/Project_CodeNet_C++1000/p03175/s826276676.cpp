//thuanqvbn03
#include <bits/stdc++.h>

using namespace std;

const int MaxN = 100005;
const long long Mod = 1000000007;

int n;
vector<int> Adj[MaxN];
long long f[MaxN][2];

void DFS(int u, int p)
{
    f[u][0] = f[u][1] = 1;
    for (auto v : Adj[u])
    {
        if (v != p)
        {
            DFS(v, u);
            f[u][0] = (f[u][0] * (f[v][0] + f[v][1])) % Mod;
            f[u][1] = (f[u][1] * f[v][0]) % Mod;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int u, v;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
    DFS(1, -1);
    cout << (f[1][0] + f[1][1]) % Mod;
    return 0;
}