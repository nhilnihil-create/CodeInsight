#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 100010;
vector<int> path;
vector<int> e[maxN];
ll a[maxN], ans[maxN];

void dfs(int pre, int cur)
{
    path.push_back(cur);
    for (auto to : e[cur])
    {
        if (to == pre) continue;
        dfs(cur, to);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(0, 1);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    int cur = 0;
    ll sum = 0;
    for (int i = n; i >= 1; i--)
    {
        ans[path[cur++]] = a[i];
        sum += a[i];
    }
    printf("%lld\n", sum - a[n]);
    for (int i = 1; i <= n; i++)
    {
        printf("%lld", ans[i]);
        if (i == n) puts("");
        else printf(" ");
    }
    return 0;
}
