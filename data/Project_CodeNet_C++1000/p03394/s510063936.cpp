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
    int n;
    cin >> n;
    if (n == 3) {
        cout << "2 5 63" << '\n';
    } else if (n == 4) {
        cout << "2 5 20 63" << '\n';
    } else if (n == 5) {
        cout << "2 5 20 30 63" << '\n';
    } else {
        vector<int> res;
        ll sum = 0;
        int i = 2;
        for ( ; i<=30000 && (int)res.size()<n; ++i) {
            if (i%2 == 0 || i%3 == 0) {
                sum += i;
                res.push_back(i);
            }
        }
        int del = -1;
        if (sum%6 == 2) {
            del = 8;
            while (i%6 != 0) ++i;
            res.push_back(i);
        } else if (sum%6 == 3) {
            del = 9;
            while (i%6 != 0) ++i;
            res.push_back(i);
        } else if (sum%6 == 5) {
            del = 9;
            while (i%6 != 4) ++i;
            res.push_back(i);
        }
        for (int j=0; j<(int)res.size(); ++j) {
            if (res.at(j) != del) {
                cout << res.at(j);
            }
            if (j == (int)res.size()-1) cout << '\n';
            else cout << ' ';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
