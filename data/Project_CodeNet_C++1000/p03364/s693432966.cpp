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
    vector<string> a(n);
    for (int i=0; i<n; i++) {
        cin >> a.at(i);
    }
    int cnt = 0;
    for (int i=0; i<n; i++) {
        bool ok = true;
        for (int j=0; j<n; j++) {
            for (int k=j+1; k<n; k++) {
                if (a.at((i+j)%n).at(k) != a.at((i+k)%n).at(j)) {
                    ok = false;
                    break;
                }
            }
            if (!ok) break;
        }
        if (ok) cnt++;
    }
    cout << cnt * n << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
