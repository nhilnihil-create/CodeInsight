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
    string s;
    cin >> s;
    int n = (int)s.size();
    s = ' ' + s;

    if (s.at(1) == '0' || s.at(n) == '1') {
        cout << -1 << '\n';
        return;
    }
    for (int i=1; i<n; ++i) {
        if (s.at(i) != s.at(n-i)) {
            cout << -1 << '\n';
            return;
        }
    }

    int par = n;
    for (int i=n-1; i>0; --i) {
        cout << i << ' ' << par << '\n';
        if (s.at(i) == '1') par = i;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
