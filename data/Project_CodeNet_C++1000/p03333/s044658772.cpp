#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using WGraph = vector<vector<pair<int, ll>>>;

template<class T>inline bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;
constexpr long long LINF = 1e18;
constexpr double EPS = 1e-10;
constexpr double PI = M_PI;

void solve() {
    int N;
    cin >> N;
    vector<ll> l(N), r(N);
    for (int i=0; i<N; ++i) cin >> l[i] >> r[i];

    sort(l.rbegin(), l.rend());
    sort(r.begin(), r.end());
    for (int i=0; i<(int)l.size(); ++i) {
        l[i] *= 2;
        if (i > 0) l[i] += l[i-1];
    }
    for (int i=0; i<(int)r.size(); ++i) {
        r[i] *= 2;
        if (i > 0) r[i] += r[i-1];
    }
    ll ans = 0;
    for (int i=0; 2*i-1<=N; ++i) {
        if (2*i-1 <= N) chmax(ans, l[i] - r[i-1]);
        if (2*i <= N) chmax(ans, l[i] - r[i]);
        if (2*i+1 <= N) chmax(ans, l[i] - r[i+1]);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
