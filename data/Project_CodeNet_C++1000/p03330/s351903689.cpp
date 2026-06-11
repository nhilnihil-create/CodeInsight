#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

int main() {
    int N, C, ans = 1e9;
    cin >> N >> C;
    vector<vector<int>> D(C, vector<int>(C)), c(N, vector<int>(N)), t(3, vector<int>(C, 0));
    rep(i, C) {
        rep(j, C) {
            cin >> D[i][j];
        }
    }
    rep(i, N) {
        rep(j, N) {
            cin >> c[i][j];
            c[i][j]--;
            t[(i + j) % 3][c[i][j]]++;
        }
    }
    rep(i, C) {
        rep(j, C) {
            if (i == j) continue;
            rep(k, C) {
                if (i == k) continue;
                if (j == k) continue;
                int s = 0;
                rep(l, C) {
                    s += D[l][i] * t[0][l];
                    s += D[l][j] * t[1][l];
                    s += D[l][k] * t[2][l];
                }
                ans = min(ans, s);
            }
        }
    }
    cout << ans << "\n";
}