#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using WGraph = vector<vector<pair<int, ll>>>;

template<class T>inline bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;
constexpr long long LINF = 1e18;
constexpr double EPS = 1e-10;
constexpr double PI = M_PI;

void dfs(int cur, int pre, vector<pair<ll, ll>> &dp, const Graph &G) {
    for (int nx : G[cur]) {
        if (nx == pre) continue;
        dfs(nx, cur, dp, G);
        (dp[cur].first *= dp[nx].first + dp[nx].second) %= MOD;
        (dp[cur].second *= dp[nx].first) %= MOD;
    }
}

void solve() {
    int N;
    cin >> N;
    Graph G(N);
    for (int i=0; i<N-1; ++i) {
        int x, y;
        cin >> x >> y;
        G[x-1].push_back(y-1);
        G[y-1].push_back(x-1);
    }

    vector<pair<ll, ll>> dp(N, make_pair(1, 1));
    dfs(0, -1, dp, G);
    cout << (dp[0].first + dp[0].second) % MOD << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
