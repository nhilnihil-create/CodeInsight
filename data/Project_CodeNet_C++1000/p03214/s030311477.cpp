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
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a.at(i);
    }
    double av = 0;
    for (int i=0; i<n; i++) {
        av += a.at(i);
    }
    av /= n;
    double mini = LINF;
    int ans = -1;
    for (int i=0; i<n; i++) {
        double diff = abs(av - a.at(i));
        if (chmin(mini, diff)) ans = i;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
