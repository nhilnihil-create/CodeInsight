#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int N, C;
    cin >> N >> C;
    vector<vector<int>> D(C, vector<int>(C));
    rep(i, C) {
        rep(j, C) {
            cin >> D[i][j];
        }
    }
    vector<vector<int>> c(N, vector<int>(N));
    rep(i, N) {
        rep(j, N) {
            cin >> c[i][j];
            c[i][j]--;
        }
    }
    vector<vector<int>> A(3, vector<int>(C, 0));
    rep(k, C) {
        rep(i, N) {
            rep(j, N) {
                A[(i + j) % 3][k] += D[c[i][j]][k];
            }
        }
    }
    int ans = 1e9;
    rep(i, C) {
        rep(j, C) {
            if (i == j) continue;
            rep(k, C) {
                if (i == k || j == k) continue;
                ans = min(ans, A[0][i] + A[1][j] + A[2][k]);
            }
        }
    }
    cout << ans << "\n";
}