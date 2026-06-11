#include <bits/stdc++.h>
#define INF 1e18
#define int long long
#define Rep(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) Rep(i, 0, n)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;
const int mod = 1000000007;
//const int mod = 998244353;

vector<int> G[100010];
bool vis[100010];

void dfs(int pos)
{
    vis[pos] = true;
    rep(i, G[pos].size()) if (!vis[G[pos][i]]) dfs(G[pos][i]);
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> x(m), y(m), z(m);
    rep(i, m) cin >> x[i] >> y[i] >> z[i];
    rep(i, m)
    {
        x[i]--;
        y[i]--;
        G[x[i]].push_back(y[i]);
        G[y[i]].push_back(x[i]);
    }
    int ans = 0;
    rep(i, n)
    {
        if (!vis[i])
        {
            ans++;
            dfs(i);
        }
    }
    cout << ans << endl;
}
