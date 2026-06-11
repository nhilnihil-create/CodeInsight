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
    int N;
    cin >> N;
    vector<vector<int>> a(N, vector<int>(N));
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            cin >> a[i][j];
        }
    }

    vector<ll> dp(1<<N);
    for (int bits=0; bits<(1<<N); ++bits) {
        for (int i=0; i<N; ++i) {
            for (int j=i+1; j<N; ++j) {
                if ((bits & (1<<i)) && (bits & (1<<j))) dp[bits] += a[i][j];
            }
        }
        for (int sub=bits; sub>0; sub=bits&(sub-1)) {
            chmax(dp[bits], dp[sub] + dp[bits&~sub]);
        }
    }
    cout << dp.back() << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
