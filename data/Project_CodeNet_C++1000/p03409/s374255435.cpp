#include <bits/stdc++.h>
using namespace std;
#define INF_LL 1LL << 40
#define INF 2000000000
#define MOD 1000000007
#define ll long long
#define all(x) x.begin(), x.end()
#define REP(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)
// typedef float double;
// typedef priority_queue prique;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<P> vp;
typedef vector<ll> vl;
typedef vector<vi> matrix;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int sign[2] = {1, -1};
template <class T> bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
struct edge {
    int to, cap, rev;
};

vector<edge> g[202];
bool used[202];

void add_edge(int from, int to, int cap) {
    g[from].push_back({to, cap, (int)g[to].size()});
    g[to].push_back({from, 0, (int)g[from].size() - 1});
}

int dfs(int v, int t, int f) {
    if(v == t)
        return f;
    used[v] = true;
    rep(i, g[v].size()) {
        edge &e = g[v][i];
        if(!used[e.to] && e.cap > 0) {
            int d = dfs(e.to, t, min(f, e.cap));
            if(d > 0) {
                e.cap -= d;
                g[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

signed main() {
    int n;
    vector<vector<edge>> g(2 * n + 2);
    cin >> n;
    rep(i, n) {
        add_edge(0, i + 1, 1);
        add_edge(n + i + 1, 2 * n + 1, 1);
    }
    vector<P> r(n), b(n);
    rep(i, n) cin >> r[i].first >> r[i].second;
    rep(i, n) cin >> b[i].first >> b[i].second;
    // cout << b[0].first << b[0].second << endl;
    rep(i, n) rep(j, n) {
        if(r[i].first < b[j].first && r[i].second < b[j].second) {
            add_edge(i + 1, n + j + 1, 1);
        }
    }
    int ans = 0;
    while(1) {
        memset(used, false, sizeof(used));
        int f = dfs(0, 2 * n + 1, INF);
        // cout << f << endl;
        if(f == 0)
            break;
        ans += f;
    }
    cout << ans << endl;
}
