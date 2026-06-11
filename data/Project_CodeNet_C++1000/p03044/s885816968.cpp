#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;
const int MAX_N = 1e5 + 2;
vector<vector<P>> G(MAX_N);
vector<int> ans(MAX_N);

void dfs(int v, int w, int c) {
    if (ans[v] != -1) return;

    if (w % 2) ans[v] = 1 - c;
    else ans[v] = c;

    for (auto p : G[v]) {
        dfs(p.first, p.second, ans[v]);
    }
}

int main()
{
    int N;
    cin >> N;

    rep(i, N - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    rep(i, N) {
        ans[i] = -1;
    }

    dfs(0, 0, 0);

    rep(i, N) cout << ans[i] << endl;

    return 0;
}