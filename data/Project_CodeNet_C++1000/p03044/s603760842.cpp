#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define pii pair<int,int>

int N;
vector<pii> G[100010];
int ans[100010];

void DFS(int v, int d, int p=0)
{
    ans[v] = d;
    for(auto e : G[v])if(e.first != p)
    {
        DFS(e.first, e.second ^ d, v);
    }
}

signed main()
{
    cin >> N;
    rep(i, N - 1)
    {
        int u, v, w;
        cin >> u >> v >> w;
        w = w % 2;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    DFS(1, 0);

    for(int i = 1; i <= N; i++)cout << ans[i] << endl;

    return 0;
}
