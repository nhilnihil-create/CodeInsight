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
    int n, q;
    string s;
    cin >> n >> q >> s;
    vector<pair<char, char>> td(q);
    for (int i=0; i<q; ++i) {
        cin >> td.at(i).first >> td.at(i).second;
    }

    auto sim = [&](int cur) -> int {
        for (int i=0; i<q; ++i) {
            if (s.at(cur) == td.at(i).first) {
                if (td.at(i).second == 'L') --cur;
                else ++cur;
            }
            if (cur == -1 || cur == n) return cur;
        }
        return cur;
    };

    int res = n;
    int ok = n, ng = -1;
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (sim(mid) == -1) ng = mid;
        else ok = mid;
    }
    res -= ng + 1;
    ok = -1, ng = n;
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (sim(mid) == n) ng = mid;
        else ok = mid;
    }
    res -= n - ng;
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
