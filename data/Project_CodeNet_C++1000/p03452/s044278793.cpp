#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
static const int dx[4] = { 0, 1, 0, -1 };
static const int dy[4] = { 1, 0, -1, 0 };
static const char dir[4] = { 'u', 'r', 'd', 'l' };
static const ll INF = 1 << 21;
static const ll MOD = 1e9 + 7;
static const int MAX_N = 1e5;
int N, M;
struct edge {
    int to,
        d;
};
vector<vector<edge>> g;
vector<int> x,used;

void dfs(int i, int d)
{
    used[i] = 1;
    x[i] = d;
    for (auto e : g[i]) {
        if (used[e.to]) {
            if (x[e.to] != x[i] + e.d) {
                puts("No");
                exit(0);
            }
        } else {
            dfs(e.to, d + e.d);
        }
    }
}

signed main()
{
    cin >> N >> M;
    g.resize(N);
    rep(i, M)
    {
        int l, r, d;
        cin >> l >> r >> d;
        --l, --r;
        g[l].emplace_back(edge{ r, d });
        g[r].emplace_back(edge{ l, -d });
    }
    used.resize(N), x.resize(N);
    rep(i, N)
    {
        if (!used[i]) {
            dfs(i, 0);
        }
    }
    puts("Yes");
    return 0;
}