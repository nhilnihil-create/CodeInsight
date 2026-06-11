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

int draw(int cur, vector<int> &color, const Graph &G, int col) {
    color[cur] = col;
    for (int nx : G[cur]) {
        if (color[nx] == -1) {
            int ret = draw(nx, color, G, 1-col);
            if (ret < 0) return -1;
        } else if (color[nx] == col) {
            return -1;
        }
    }
    return 0;
}

void solve() {
    ll N, M;
    cin >> N >> M;
    Graph G(N);
    for (int i=0; i<M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }

    vector<int> color(N, -1);
    int ret = draw(0, color, G, 0);
    if (ret < 0) {
        cout << N * (N-1) / 2 - M << '\n';
    } else {
        ll b = count(color.begin(), color.end(), 0);
        ll w = count(color.begin(), color.end(), 1);
        cout << b * w - M << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
