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

long long gcd(long long a, long long b) {
    if (a < b) std::swap(a, b);
    if (b == 0) return a;

    while (b > 0) {
        long long tmp = b;
        b = a%b;
        a = tmp;
    }
    return a;
}

void solve() {
    int T;
    cin >> T;
    vector<bool> res(T);
    for (int i=0; i<T; ++i) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a < b) {
            res[i] = false;
            continue;
        }
        if (d < b) {
            res[i] = false;
            continue;
        }
        if (c >= b) {
            res[i] = true;
            continue;
        }
        ll g = gcd(b, d);
        if (b - g + a%g > c) res[i] = false;
        else res[i] = true;
    }
    for (int i=0; i<T; ++i) cout << (res[i] ? "Yes" : "No") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
