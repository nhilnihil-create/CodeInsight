#include <bits/stdc++.h>
#define ll long long int
#define mod_ceil(a, b) (a % b) ? a / b + 1 : a / b
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, m, a, b, ans = 0;
    cin >> n >> m;
    vector<ll> G[n];
    pair<ll, ll> E[m];
    vector<bool> B(m, false);
    for (ll i = 0; i < m; i++)
    {
        cin >> a >> b;
        G[a - 1].push_back(b - 1);
        G[b - 1].push_back(a - 1);
        E[i] = {a - 1, b - 1};
    }
    for (ll i = 0; i < m; i++)
    {
        ll l = E[i].first, r = E[i].second;
        for (auto it = G[l].begin(); it != G[l].end(); it++)
        {
            if (*it == r)
            {
                G[l].erase(it);
                break;
            }
        }
        for (auto it = G[r].begin(); it != G[r].end(); it++)
        {
            if (*it == l)
            {
                G[r].erase(it);
                break;
            }
        }
        vector<bool> vis(n, false);
        queue<ll> Q;
        Q.push(l);
        while (!Q.empty())
        {
            ll top = Q.front();
            Q.pop();
            if (vis[top])
                continue;
            vis[top] = true;
            for (ll j = 0; j < G[top].size(); j++)
            {
                if (!vis[G[top][j]])
                {
                    Q.push(G[top][j]);
                }
                if (G[top][j] == r)
                {
                    B[i] = true;
                }
            }
        }
        G[l].push_back(r);
        G[r].push_back(l);
    }
    cout << count(B.begin(), B.end(), false) << endl;
}