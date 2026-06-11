#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
ll INF = 1e9 + 7;
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> dis(n, -1);
    function<void(int, int)> dfs = [&](int v, int d) 
    {
        dis[v] = d;
        for(int nx : g[v])
        {
            if(dis[nx] >= 0) continue;
            dfs(nx, d + 1);
        }
    };
    dfs(0, 1);
    int ma = 0;
    int pos = 0;
    for(int i = 0; i < n; i++)
    {
        if(ma < dis[i])
        {
            ma = dis[i];
            pos = i;
        }
    }
    for(int i = 0; i < n; i++) dis[i] = -1;
    dfs(pos, 1);
    ma = 0;
    for(int i = 0; i < n; i++)
    {
        if(ma < dis[i])
        {
            ma = dis[i];
        }
    }
    if(ma % 3 == 2) cout << "Second" << endl;
    else cout << "First" << endl;
}
