#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(a) begin(a), end(a)
#define pb emplace_back

const ll maxn = 5e5 + 5;
ll n, m;
vector<ll> g[maxn];
ll used[maxn];

void dfs(ll i)
{
    if (used[i] == 2) return;
    if (used[i] == 1)
    {
        cout << "Yes" << endl;
        exit(0);
    }
    used[i] = 1;
    for (ll j : g[i])
    {
        dfs(j);
    }
    used[i] = 2;
}

int main()
{
    cin >> n >> m;
    string s;
    s.reserve(maxn);
    cin >> s;
    while (m--)
    {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        if (s[a] == s[b])
        {
            g[a].pb(b + n);
            g[b].pb(a + n);
        }
        else
        {
            g[a + n].pb(b);
            g[b + n].pb(a);
        }
    }
    for (ll i = 0; i < n; ++i)
    {
        if (!used[i])
        {
            dfs(i);
        }
    }
    cout << "No" << endl;
    return 0;
}
