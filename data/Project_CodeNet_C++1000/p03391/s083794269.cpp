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
    vector<int> a(N), b(N);
    for (int i=0; i<N; ++i) cin >> a[i] >> b[i];

    ll sum = 0;
    for (int x : a) sum += x;
    int val = INF+1, ind = -1;
    for (int i=0; i<N; ++i) if (a[i] > b[i] && chmin(val, b[i])) ind = i;
    if (ind == -1) cout << 0 << '\n';
    else cout << sum - val << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
