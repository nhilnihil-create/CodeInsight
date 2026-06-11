#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    int N, C;
    cin >> N >> C;
    vector<vector<int>> D(C, vector<int>(C));
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < C; j++) {
            cin >> D[i][j];
        }
    }
    vector<vector<int>> c(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> c[i][j];
            c[i][j]--;
        }
    }

    map<int, int> cnt[3];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cnt[(i + j + 2) % 3][c[i][j]]++;
        }
    }

    int ans = 1e9;
    for (int l = 0; l < C; l++) {
        for (int m = 0; m < C; m++) {
            for (int n = 0; n < C; n++) {
                if (l == m || m == n || n == l)
                    continue;

                int tmp = 0;
                for (int i = 0; i < 3; i++) {
                    for (auto p : cnt[i]) {
                        if (i == 0) {
                            tmp += D[p.first][l] * p.second;
                        } else if (i == 1) {
                            tmp += D[p.first][m] * p.second;
                        } else {
                            tmp += D[p.first][n] * p.second;
                        }
                    }
                }
                ans = min(ans, tmp);
            }
        }
    }
    cout << ans << endl;
}
