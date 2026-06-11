#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5, mod = 1e9 + 7, inf = INT_MAX;

int par[N], rnk[N];
ll siz[N];

int findp(int x)
{
    return (par[x] == x? x: par[x] = findp(par[x]));
}

bool iscon(int x, int y)
{
    return (findp(x) == findp(y));
}

void con(int x, int y)
{
    int px = findp(x), py = findp(y);
    if (rnk[px] > rnk[py])
        par[py] = px;
    else if (rnk[px] < rnk[py])
        par[px] = py;
    else
        par[px] = py, rnk[px]++,
        siz[py] += siz[px];
}

int main()
{
    //ios::sync_with_stdio(false);cin.tie(nullptr);ios_base::sync_with_stdio(false);
    ll n, m;
    pair<int, int> a[N];
    cin >> n >> m;
    ll beg = n * (n - 1) / 2;
    for (int i = 1; i <= n; i++)
        siz[i] = 1, par[i] = i;
    stack<ll> s;
    for (int i = 0; i < m; i++)
        cin >> a[i].first >> a[i].second;
    for (int i = m--; i > -1; i--)
    {
        if (!iscon(a[i].first, a[i].second))
            beg -= siz[par[a[i].first]] * siz[par[a[i].second]],
                    con(a[i].first, a[i].second);
        s.push(beg);
    }
    s.pop();
    while (!s.empty())
        cout << s.top() << endl,
                s.pop();
    return 0;
}