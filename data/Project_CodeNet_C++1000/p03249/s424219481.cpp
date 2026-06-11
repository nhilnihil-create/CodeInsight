#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 1e5 + 10;

int sz[maxn], tot;
ll d[maxn], dis[maxn];
map<ll, int> mp;
vector<int> edge[maxn];
int ans[maxn][2];

void dfs(int u, int pre)
{
    for(auto v : edge[u])
    {
        if(v == pre) continue;
        dis[v] = dis[u] + 1;
        ans[tot][0] = u, ans[tot++][1] = v;
        dfs(v, u);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
    {
        scanf("%lld", &d[i]);
        mp[d[i]] = i, sz[i] = 1;
    }
    int cnt = 0;
    for(auto it = mp.rbegin(); it != mp.rend(); it ++)
    {
        int v = it->second, u = mp[it->first + 2 * sz[v] - n];
        if(!u || u == v) return puts("-1"), 0;
        edge[u].push_back(v);
        edge[v].push_back(u);
        sz[u] += sz[v];
        if(++cnt == n - 1) break;
    }
    int rt = mp.begin()->second;
    dfs(rt, 0);
    if(accumulate(dis + 1, dis + n + 1, 0ll) != d[rt]) return puts("-1"), 0;
    for(int i = 0; i < tot; i ++)
        printf("%d %d\n", ans[i][0], ans[i][1]);
    return 0;
}
