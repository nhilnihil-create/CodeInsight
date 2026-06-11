#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define endl "\n"
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

int n, m;
vector<vector<int>> g;
vector<int> color;

bool dfs(int v, int c) {
    color[v] = c;
    for(const auto &u : g[v]) {
        if(color[u] == c) {
            return false;
        }
        if(color[u] == 0 && !dfs(u, -c)) {
            return false;
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    g.resize(n);
    color.resize(n, 0);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    bool f = dfs(0, 1);
    if(f) {
        ll b = count(ALL(color), 1);
        ll w = n - b;
        cout << b * w - (ll)m << endl;
    } else {
        cout << (ll)n * (n - 1) / 2 - (ll)m << endl;
    }
}