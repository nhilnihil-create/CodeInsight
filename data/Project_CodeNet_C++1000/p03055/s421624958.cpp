#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> d(n);
    for(int i = 0; i < n; i++)
    {
        d[i] = -1;
    }
    function<void(int)> dfs = [&](int v)
    {
        for(int nx : g[v])
        {
            if(d[nx] != -1) continue;
            d[nx] = d[v] + 1;
            dfs(nx);
        }
    };
    d[0] = 0;
    dfs(0);
    int pos = 0;
    int ma = 0;
    for(int i = 0; i < n; i++)
    {
        if(ma < d[i])
        {
            ma = d[i];
            pos = i;
        }
    }
    for(int i = 0; i < n; i++)
    {
        d[i] = -1;
    }
    d[pos] = 0;
    dfs(pos);
    ma = 0;
    pos = 0;
    for(int i = 0; i < n; i++)
    {
        if(ma < d[i])
        {
            ma = d[i];
            pos = i;
        }
    }
    ma++;
    if(ma % 3 == 2)
    {
        cout << "Second" << endl;
    }
    else
    {
        cout << "First" << endl;
    }
}
