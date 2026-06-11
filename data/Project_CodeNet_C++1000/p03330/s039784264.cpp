#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
    int N, C;
    cin >> N >> C;
    vector<vector<int>> D(C, vector<int>(C));
    rep(i, C) {
        rep(j, C) {
            cin >> D[i][j];
        }
    }

    vector<vector<int>> E(N, vector<int>(N));
    rep(i, N) {
        rep(j, N) {
            cin >> E[i][j];
            E[i][j]--;
        }
    }

    vector<vector<int>> G(3, vector<int>(C));
    rep(i, N) {
        rep(j, N) {
            G[(i + j) % 3][E[i][j]]++;
        }
    }

    int ans = __INT32_MAX__;
    // i+j%3 == 0
    for (int c1 = 0; c1 < C; c1++) {
        // i+j%3 == 1
        for (int c2 = 0; c2 < C; c2++) {
            if (c1 == c2) continue;
            // i+j%3 == 2
            for (int c3 = 0; c3 < C; c3++) {
                if (c1 == c3 || c2 == c3) continue;

                int x = 0;
                // aをc1に塗り替える
                for (int a = 0; a < C; a++) {
                    x += D[a][c1] * G[0][a];
                }

                // aをc2に塗り替える
                for (int a = 0; a < C; a++) {
                    x += D[a][c2] * G[1][a];
                }

                // aをc3に塗り替える
                for (int a = 0; a < C; a++) {
                    x += D[a][c3] * G[2][a];
                }

                ans = min(ans, x);
            }
        }
    }
    cout << ans << endl;
}