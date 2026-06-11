#include<bits/stdc++.h>
#define fo(i, a, b) for (int i = (a); i <= (b); ++i)
#define fd(i, a, b) for (int i = (a); i >= (b); --i)
#define edge(i, u) for (int i = head[u], v = e[i].v; i; i = e[i].nxt, v = e[i].v)
#define N 200005
#define ls(u) t[u].s[0]
#define rs(u) t[u].s[1]
#define lowbit(x) x & -x
#define ll long long
#define pb push_back
int n, m, a[N], x, y, k, ans;
std::set<int> q[N];
int main ()
{
    scanf("%d %d %d", &n, &m, &k);
    fo (i, 1, m) q[i].insert(n + 1);
    fo (i, 1, k)
    {
        scanf("%d %d", &x, &y);
        q[y].insert(x);
    }
    x = 1; y = 1;
    ans = *q[1].upper_bound(1) - 1;
    fo (x, 2, n)
    {
        if (*q[y + 1].lower_bound(x) > x) ++y;
        ans = std::min(ans, (int)*q[y].lower_bound(x) - 1);
    }
    printf("%d", ans);
    return 0;
}