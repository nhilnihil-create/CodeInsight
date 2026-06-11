#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const ll MOD = 1e9 + 7;
int n, x, y;
vector<int> G[100009];
ll dp[100009][2];  // 0 - white, 1 - black
int vis[100009];

void solve(int v)
{
    vis[v] = 1;

    dp[v][0] = 1;
    dp[v][1] = 1;

    for (int i = 0; i < G[v].size(); i++)
    {
        int w = G[v][i];

        if (vis[w] == 0)
        {
            solve(w);
            dp[v][0] *= (dp[w][0] + dp[w][1]);
            dp[v][1] *= (dp[w][0]);

            dp[v][0] %= MOD;
            dp[v][0] += MOD;
            dp[v][0] %= MOD;

            dp[v][1] %= MOD;
            dp[v][1] += MOD;
            dp[v][1] %= MOD;
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> x >> y;

        G[x].pb(y);
        G[y].pb(x);
    }

    solve(1);

    ll ans = dp[1][0] + dp[1][1];
    ans += MOD;
    ans %= MOD;

    cout << ans << "\n";
}