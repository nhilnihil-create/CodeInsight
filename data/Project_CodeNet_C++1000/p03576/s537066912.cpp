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
    int n, K;
    cin >> n >> K;
    vector<pair<ll, ll>> a(n);
    for (int i=0; i<n; i++) {
        cin >> a.at(i).first >> a.at(i).second;
    }
    ll res = 1e20;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                for (int l=0; l<n; l++) {
                    ll xmin = a.at(i).first, xmax = a.at(j).first, ymin = a.at(k).second, ymax = a.at(l).second;
                    int cnt = 0;
                    for (int m=0; m<n; m++) {
                        if (xmin <= a.at(m).first && a.at(m).first <= xmax && ymin <= a.at(m).second && a.at(m).second <= ymax) {
                            cnt++;
                        }
                    }
                    if (cnt >= K) {
                        chmin(res, (xmax - xmin) * (ymax - ymin));
                    }
                }
            }
        }
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
