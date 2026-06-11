#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef long long ll;

int N, C, D[31][31], Cnt[3][31];

int main() {
    cin >> N >> C;
    for (int i = 1; i <= C; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> D[i][j];
        }
    }
    int c;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> c;
            Cnt[(i+j) % 3][c]++;
        }
    }

    int res = 1 << 30;
    for (int c0 = 1; c0 <= C; c0++) {
            for (int c1 = 1; c1 <= C; c1++) {
                if (c0 == c1) { continue; }
                    for (int c2 = 1; c2 <= C; c2++) {
                        if (c0 == c2 || c1 == c2) { continue; }

                        int tmp = 0;
                        for (int c = 1; c <= C; c++) {
                            tmp += Cnt[0][c] * D[c][c0];
                            tmp += Cnt[1][c] * D[c][c1];
                            tmp += Cnt[2][c] * D[c][c2];
                        }
                        res = min(res, tmp);
                    }
            }
    }

    cout << res << endl;
}

/*
int main() {
    int N, C, D[300001], Co[300001];
    cin >> N >> C;
    for (int i = 1; i <= C; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> D[i*C + j];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> Co[i*N + j];
        }
    }

    ll D0[31], D1[31], D2[31];

    for (int c = 1; c <= C; c++) {
        ll ds[3] = { 0, 0, 0 };

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                int orig = Co[i * N + j];
                ll d = D[orig * C + c];
                ds[(i + j) % 3] += d;
            }
        }

        D0[c] = ds[0];
        D1[c] = ds[1];
        D2[c] = ds[2];
    }

    ll ddd = 99999999999999;
    for (int i = 1; i <= C; i++) {
        for (int j = 1; j <= C; j++) {
            if (i == j) { continue; }
            for (int k = 1; k <= C; k++) {
                if (i == k || j == k) { continue; }

                ddd = min(ddd, (ll)(D0[i] + D1[j] + D2[k]));
            }
        }
    }

    cout << ddd<< endl;
}
*/