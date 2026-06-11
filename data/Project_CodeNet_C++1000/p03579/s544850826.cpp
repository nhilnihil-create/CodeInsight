#include <bits/stdc++.h>
#define repd(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) repd(i, 0, n)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

vector<int> color;
vector<vector<int>> G;

bool dfs(int v, int c)
{
    color[v] = c;
    rep(i, G[v].size())
    {
        if (color[G[v][i]] == c)
        {
            return false;
        }
        if (color[G[v][i]] == 0 && !dfs(G[v][i], -c))
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int N, M;
    cin >> N >> M;

    G = vector<vector<int>>(N);
    color = vector<int>(N, 0);

    rep(i, M)
    {
        int s, t;
        cin >> s >> t;
        G[s - 1].push_back(t - 1);
        G[t - 1].push_back(s - 1);
    }

    bool flag = true;
    rep(i, N)
    {
        if (color[i] == 0)
        {
            flag = dfs(i, 1);
            if (!flag)
            {
                break;
            }
        }
    }

    int B = 0, W = 0;
    ll ans;

    if (flag)
    {
        rep(i, N)
        {
            if (color[i] == 1)
            {
                B++;
            }
            else if (color[i] == -1)
            {
                W++;
            }
        }
        ans = 1LL * B * W - M;
    }
    else
    {
        ans = ((1LL * N * (N - 1)) / 2) - M;
    }

    cout << ans << endl;

    return 0;
}
