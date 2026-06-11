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
    ll N, A, B;
    cin >> N >> A >> B;

    if (A * B < N || N + 1 < A + B) {
        cout << -1 << '\n';
        return;
    }

    vector<int> res;
    int f = B != 1 ? (N - A) / (B - 1) : N, m = B != 1 ? (N - A) % (B - 1) : 1;
    int cnt = 0, cur = B;
    while (cur <= N) {
        if (cnt < f) {
            for (int i=cur; i>cur-B; --i) res.push_back(i);
            if (cnt == f-1) cur += m+1;
            else cur += B;
        } else if (cnt == f) {
            for (int i=cur; i>=cur-m; --i) res.push_back(i);
            ++cur;
        } else {
            res.push_back(cur);
            ++cur;
        }
        ++cnt;
    }
    for (int i=0; i<N; ++i) {
        cout << res[i];
        if (i == N-1) cout << '\n';
        else cout << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
