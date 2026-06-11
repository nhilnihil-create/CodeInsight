#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
using Graph = vector<vector<int>>;
const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

vector<int> dp(1e5 + 100, 0);
Graph G(1e5 + 100);

int rec(int v)
{
    if (dp[v] != 0)
        return dp[v];
    int ret = 0;
    for (int i = 0; i < G[v].size(); i++) {
        int pv = G[v][i];
        ret = max(ret, rec(pv) + 1);
    }

    return dp[v] = ret;
}
int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        G[y].push_back(x);
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, rec(i));
    }
    cout << ans << endl;
    return 0;
}