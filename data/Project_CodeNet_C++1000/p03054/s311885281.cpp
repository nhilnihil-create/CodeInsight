#pragma region Macros
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using WGraph = vector<vector<pair<int, ll>>>;

template<class T>inline bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;
constexpr double EPS = 1e-10;
constexpr double PI = M_PI;
#pragma endregion

void solve() {
    int h, w, n, cx, cy;
    cin >> h >> w >> n >> cy >> cx;
    string s, t;
    cin >> s >> t;
    int xmin = 1, xmax = w, ymin = 1, ymax = h;
    for (int i=n-1; i>=0; i--) {
        char c = t.at(i);
        if (c == 'L' && xmax < w) xmax++;
        else if (c == 'R' && xmin > 1) xmin--;
        else if (c == 'U' && ymax < h) ymax++;
        else if (c == 'D' && ymin > 1) ymin--;
        c = s.at(i);
        if (c == 'L') xmin++;
        else if (c == 'R') xmax--;
        else if (c == 'U') ymin++;
        else if (c == 'D') ymax--;
        if (xmin > xmax || ymin > ymax) break;
    }
    if (xmin <= cx && cx <= xmax && ymin <= cy && cy <= ymax) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
