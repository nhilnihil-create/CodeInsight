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

int main()
{
    //ios::sync_with_stdio(false);cin.tie(nullptr);ios_base::sync_with_stdio(false);
    ll n, m;
    pair<int, int> a[N];
    cin >> n >> m;
    ll beg = n * (n - 1) / 2;
    for (int i = 1; i <= n; i++)
        siz[i] = 1, par[i] = i;
    for (int i = 0; i < m; i++)
        cin >> a[i].first >> a[i].second;
    stack<ll> s;
    for (int i = m - 1; i >= 0; i--)
    {
        s.push(beg);
        int x = findp(a[i].first), y = findp(a[i].second);
        if (x != y)
            par[y] = x,
            beg -= siz[x] * siz[y],
            siz[x] += siz[y];
    }
    while (!s.empty())
        cout << s.top() << endl,
        s.pop();
    return 0;
}