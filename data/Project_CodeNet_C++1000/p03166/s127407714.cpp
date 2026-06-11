#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m, a, b, ans;
vector<int> G[100009];
int we[100009], dp[100009];
queue<int> Q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        G[a].pb(b);
        we[b]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (we[i] == 0) Q.push(i);
    }

    while (!Q.empty())
    {
        int v = Q.front();
        Q.pop();

        for (int i = 0; i < G[v].size(); i++)
        {
            int w = G[v][i];

            dp[w] = max(dp[w], dp[v] + 1);
            we[w]--;

            if (!we[w]) Q.push(w);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dp[i]);
    }

    cout << ans << "\n";
}