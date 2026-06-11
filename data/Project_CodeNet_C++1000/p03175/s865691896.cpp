#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll max_N = 1e5 + 50, INF = 1e15, MOD = 1e9 + 7;
ll N;
vector<ll> adj[max_N];
ll DP[max_N][2];
// 0 for white and 1 for black

void dfs(ll curr, ll par)
{
    ll w_prdt = 1, bl_prdt = 1;
    for (auto &neigh : adj[curr])
    {
        if (neigh == par)
            continue;
        dfs(neigh, curr);
        w_prdt *= (DP[neigh][0] + DP[neigh][1]);
        bl_prdt *= DP[neigh][0];
        w_prdt %= MOD;
        bl_prdt %= MOD;
    }
    DP[curr][0] = (w_prdt), DP[curr][1] = bl_prdt;
}

int main()
{
    cin >> N;
    ll x, y;
    for (int i = 1; i < N; ++i)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, -1);
    cout << (DP[1][0] + DP[1][1]) % MOD << "\n";
    return 0;
}