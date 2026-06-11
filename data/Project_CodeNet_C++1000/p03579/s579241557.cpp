#include <bits/stdc++.h>

using namespace std;
using Graph = vector<vector<int>>;
Graph G;
vector<int>color;

bool dfs(int v, int c)
{
    color[v] = c;
    for(auto nx: G[v])
    {
        if(color[nx] != -1)
        {
            if(color[nx] == c)
            {
                return false;
            }
            continue;
        }
        if(!dfs(nx,1-c))
        {
            return false;
        }
    }
    return true;
}
int main()
{
    long long int n,m;
    cin >> n >> m;
    G.resize(n);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    color.assign(n,-1);
    long long int ans;
    if(dfs(0,0))
    {
        long long int c = 0;
        long long int d = 0;
        for(auto x: color)
        {
            if(x == 0)
            {
                c++;
            }
            else
            {
                d++;
            }
        }
        ans = c*d - m;
        cout << ans << endl;
    }
    else
    {
        ans = n*(n-1) / 2 - m;
        cout << ans << endl;
    }
    return 0;
}