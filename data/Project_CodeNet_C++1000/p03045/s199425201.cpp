#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9+7;
const ll LINF = 1LL<<60;

const int MAXN = 100000;

bool seen[MAXN];

void dfs(Graph &G, int v) {
    seen[v] = 1;
    for (auto nv : G[v]) {
        if (seen[nv] == 1) continue;
        dfs(G, nv);
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    Graph G(n);
    rep(i, m) {
        int x, y, z;
        cin >> x >> y >> z;
        --x, --y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    int res = 0;
    rep(i, n) {
        if (seen[i] != 0) continue;
        dfs(G, i);
        res++;
    }

    cout << res << endl;

    return 0;
}