#include "bits/stdc++.h"
using namespace std;
const int MOD = 1e9 + 7;
typedef long long lint;
const int INF = 1e7;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repi(i, k, n) for (int i = (k); i < (int)(n); ++i)
typedef pair<int, int> P;
typedef vector<lint> vi;
typedef vector<vi> vvi;
#define all(x) (x).begin(), (x).end()
#define pb push_back
vvi G;
vi color;
bool dfs(int u, int col)
{
    color[u] = col;
    rep(i, G[u].size())
    {
        int v = G[u][i];
        if (color[v] == col)
        {
            return false;
        }
        if (color[v] == 0 && !dfs(v, -col))
        {
            return false;
        }
    }
    return true;
}
int main()
{
    lint n, m;
    cin >> n >> m;
    G.resize(n);
    color.resize(n);
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    if (dfs(0, 1))
    {
        lint black = 0;
        lint white = 0;
        rep(i, n)
        {
            if (color[i] == 1)
            {
                black++;
            }
            if (color[i] == -1)
            {
                white++;
            }
        }
        cout << black * white - m << endl;
    }
    else
    {
        cout << (n * (n - 1)) / 2 - m << endl;
    }
    return 0;
}