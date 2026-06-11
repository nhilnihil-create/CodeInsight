#include <bits/stdc++.h>
#define ll long long int
#define mod_ceil(a, b) (a % b) ? a / b + 1 : a / b
using namespace std;

ll U[100010];

ll root(ll x)
{
    while (x != U[x])
    {
        U[x] = U[U[x]];
        x = U[x];
    }
    return x;
}

void Union(ll x, ll y)
{
    ll root_x = root(x);
    ll root_y = root(y);
    U[root_x] = root_y;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, m, x, y;
    cin >> n >> m;
    vector<ll> P(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> P[i];
    }
    // initialize dsu
    for (ll i = 1; i <= n; i++)
    {
        U[i] = i;
    }
    for (ll i = 0; i < m; i++)
    {
        cin >> x >> y;
        Union(x, y);
    }
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (root(i) == root(P[i]))
            ans++;
    }
    cout << ans << endl;
}