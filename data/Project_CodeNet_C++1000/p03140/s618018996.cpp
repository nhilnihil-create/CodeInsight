#pragma region Macros
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using WGraph = vector<vector<pair<int, ll>>>;

template<class T>bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
#pragma endregion

void solve() {
    int n;
    string a, b, c;
    cin >> n >> a >> b >> c;
    int cnt = 0;
    for (int i=0; i<n; i++) {
        if (a.at(i) == b.at(i) && b.at(i) == c.at(i)) {
        } else if (a.at(i) == b.at(i)) {
            cnt++;
        } else if (b.at(i) == c.at(i)) {
            cnt++;
        } else if (c.at(i) == a.at(i)) {
            cnt++;
        } else {
            cnt += 2;
        }
    }
    cout << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
