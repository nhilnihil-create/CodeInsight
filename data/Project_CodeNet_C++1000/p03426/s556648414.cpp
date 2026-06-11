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

void solve() {
    int H, W, D;
    cin >> H >> W >> D;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i=0; i<H; ++i) {
        for (int j=0; j<W; ++j) {
            cin >> A[i][j];
        }
    }
    int Q;
    cin >> Q;
    vector<pair<int, int>> lr(Q);
    for (int i=0; i<Q; ++i) cin >> lr[i].first >> lr[i].second;

    vector<pair<int, int>> rev(H*W+1);
    for (int i=0; i<H; ++i) {
        for (int j=0; j<W; ++j) {
            rev[A[i][j]] = make_pair(i, j);
        }
    }
    vector<ll> sum(H*W+1);
    for (int i=1; i<H*W+1; ++i) {
        if (i > D) {
            int pi = rev[i-D].first, pj = rev[i-D].second;
            int ci = rev[i].first, cj = rev[i].second;
            sum[i] = sum[i-D] + abs(pi - ci) + abs(pj - cj);
        }
    }
    for (auto p : lr) cout << sum[p.second] - sum[p.first] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
