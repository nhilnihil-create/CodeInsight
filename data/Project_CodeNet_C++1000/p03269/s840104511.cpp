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
    int L;
    cin >> L;

    int N = 20;
    int M = 0;
    WGraph res(N);
    for (int i=0; i<N-1; ++i) {
        res[i].push_back({i+1, 0});
        ++M;
    }
    --L;
    int cur = 0;
    for ( ; cur<N-1; ++cur) {
        if (L >= (1 << (cur+1))) {
            res[N-cur-2].push_back({N-cur-1, (1<<cur)});
            ++M;
        } else {
            break;
        }
    }
    int mod = L - (1<<cur) + 1;
    int c = 1 << cur;
    if (cur == 19) --cur;
    for (int i=0; i<cur+1; ++i) {
        if (mod & (1<<i)) {
            res[N-cur-2].push_back({N-i-1, c});
            ++M;
            c += (1<<i);
        }
    }

    cout << N << ' ' << M << '\n';
    for (int i=0; i<N; ++i) for (auto p : res[i]) cout << i+1 << ' ' << p.first+1 << ' ' << p.second << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
