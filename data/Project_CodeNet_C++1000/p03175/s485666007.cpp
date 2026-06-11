#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<int>> edges;
const int mod = 1e9 + 7;
vector<int> dfs(int i, int par)
{
    int white = 1, black = 1;
    for (int j : edges[i])
    {
        if (par != j)
        {
            vector<int> temp = dfs(j, i);
            int w = temp[0];
            int b = temp[1];
            white = (white % mod * (w+b) % mod ) % mod;
            black = (black % mod * w % mod) % mod;
        }
    }
    return {white, black};
}
int32_t main()
{
    int n,m;
    cin >> n;// >> m;
    m=n-1;
    edges = vector<vector<int>>(n);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    vector<int> ans = dfs(0, -1);
    ans[0] = (ans[0] % mod + ans[1] % mod) % mod;
    cout << ans[0];
    return 0;
}
