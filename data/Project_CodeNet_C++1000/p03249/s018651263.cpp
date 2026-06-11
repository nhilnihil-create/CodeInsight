#include <bits/stdc++.h>
using namespace std;

int n, sz[100010];
long long d[100010];
map<long long, int> mp;
vector<int> e[100010];

long long dfs(int x, int f)
{
    long long ans = 0;
    for (int y : e[x])
    {
        if (y == f) continue;
        ans += dfs(y, x) + sz[y];
    }
    return ans;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &d[i]);
        mp[d[i]] = i;
        sz[i] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        auto it = mp.rbegin();
        long long hh = it->first + 2 * sz[it->second] - n;
        // printf("%d %d\n", mp[hh], it->second);
        if (!mp.count(hh) || hh == it->first)
        {
            puts("-1");
            return 0;
        }
        // ans.emplace_back(mp[hh], it->second);
        e[mp[hh]].push_back(it->second);
        e[it->second].push_back(mp[hh]);
        sz[mp[hh]] += sz[it->second];
        mp.erase(it->first);
    }
    if (dfs(mp.begin()->second, 0) == mp.begin()->first)
    {
        for (int i = 1; i <= n; i++)
            for (int j : e[i])
                if (j > i)
                    printf("%d %d\n", i, j);
    }
    else puts("-1");
}