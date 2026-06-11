#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return 1; } return 0; };
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return 1; } return 0; };

const ll INF = 1LL << 60;

ll p[100010][3];
ll dp[100010][3];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> p[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (j == k) continue;
                chmax(dp[i + 1][k], dp[i][j] + p[i][k]);
            }
        }
    }

    ll res = 0;
    for (int i = 0; i < 3; i++) {
        chmax(res, dp[n][i]);
    }
    cout << res << endl;
}