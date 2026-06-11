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

constexpr ll mod = 1e9 + 7;

void solve() {
    int n, c;
    cin >> n >> c;
    vector<pair<int, int>> time(n);
    vector<int> channel(n);
    for (int i=0; i<n; i++) {
        cin >> time.at(i).first >> time.at(i).second >> channel.at(i);
        time.at(i).first--;
    }

    vector<int> cnt(1e5+1, 0);
    for (int i=1; i<=c; i++) {
        vector<int> tmp(1e5+1, 0);
        for (int j=0; j<n; j++) {
            if (channel.at(j) == i) {
                tmp.at(time.at(j).first)++;
                tmp.at(time.at(j).second)--;
            }
        }
        for (int j=1; j<1e5+1; j++) {
            tmp.at(j) += tmp.at(j-1);
        }
        for (int j=0; j<1e5+1; j++) {
            if (tmp.at(j)) {
                cnt.at(j)++;
            }
        }
    }
    int ans = 0;
    for (int i=0; i<1e5+1; i++) {
        chmax(ans, cnt.at(i));
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
