#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;
#define lcm(x, y) ((x) * (y) / __gcd((x), (y)))
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define debug(x) cout << #x << " : " << x << endl
#define part cout << "----------------------------------\n";
#include <iostream>

#define fastinput                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

LL N = 1e5;
vector<pair<LL, LL>> adj[(LL)1e5 + 1];
vector<bool> visited((LL)1e5 + 1, false);
//vector<int> color((LL)1e5 + 1, -1);
void dfs(LL s)
{
    if (!visited[s])
    {
        visited[s] = true;
        //color[s] = col;
        for (auto x : adj[s])
        {
            if (x.second & 1)
            {
                dfs(x.first);
            }
            else
            {
                dfs(x.first);
            }
        }
    }
}

int main()
{
    fastinput;
    LL n, i, j, k, t, temp, M, tc;
    cin >> n>>tc;
    for (i = 1; i <= tc; i++)
    {
        cin >> j >> k >> t;
        adj[j].pb({k, t});
        adj[k].pb({j, t});
    }

    LL cnt = 0;
    for (i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            cnt++;
        }
    }
    cout<<cnt<<endl;

    return 0;
}
