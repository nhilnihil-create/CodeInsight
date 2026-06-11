#include<bits/stdc++.h> 
#define Re register
#define fo(i, a, b) for (Re int i = (a); i <= (b); ++i)
#define fd(i, a, b) for (Re int i = (a); i >= (b); --i)
#define edge(i, u) for (Re int i = head[u], v = e[i].v; i; i = e[i].nxt, v = e[i].v)
#define pb push_back
#define F first
#define S second
#define ll long long
#define inf 1000000007
#define mp std::make_pair
#define lowbit(x) (x & -x)
#define eps 1e-4
#define itset std::set<node>::iterator
#define lb lower_bound
#define N 1000005
#define M 4000005
int n, f[N][2], a[N], tmp[2];
inline void update (int s, int x)
{
    if (f[s][0] < x)
        f[s][1] = f[s][0], f[s][0] = x;
    else
    if (f[s][1] < x)
        f[s][1] = x;
}
int main ()
{
    scanf("%d", &n);
    int up = (1 << n) - 1;
    fo (i, 0, up) {scanf("%d", &a[i]); f[i][0] = a[i]; f[i][1] = -inf;}
    fo (i, 1, n)
    {
        fo (s, 1, up)
        {
            if (!(s & 1 << i - 1)) continue;
            int pre = s ^ 1 << i - 1;
            update(s, f[pre][0]);
            update(s, f[pre][1]);
        }
    }
    int ans = 0;
    fo (i, 1, up)
    {
        ans = std::max(ans, f[i][0] + f[i][1]);
        printf("%d\n", ans);
    }
    return 0;
}