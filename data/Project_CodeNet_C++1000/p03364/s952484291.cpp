#include <bits/stdc++.h>

using namespace std;

const int N = 302;

int n, nn, ans, cnt[N * 2];
char a[N * 2][N * 2];
bool chk[N * 4][N][N];

void enter() {
    cin >> n;
    nn = n * 2;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            a[i + n][j + n] = a[i + n][j] = a[i][j + n] = a[i][j];
        }
}

bool get(bool (&f)[N][N], int l, int r) {
    return l <= r ? f[l % n][r % n] : true;
}

void solve() {
    for (int i = 2; i <= n + 1; ++i) cnt[i - 2] = i - 1;
    for (int i = n + 2, j = 1; i <= n * 2; ++i, ++j) cnt[i - 2] = n - j;
    for (int i = 1; i < nn; ++i) {
        // update
        for (int j = 1; j <= nn; ++j) {
            int s = i + j;
            int li = i - min(i, nn - j + 1);
            for (int pi = i; pi > li; --pi) {
                bool tmp = get(chk[s], pi + 1, i - 1) & (a[i][j] == a[pi][s - pi]);
                chk[s][pi % n][i % n] = tmp;
            }
        }

        // count
        if (i < n) continue;
        int ii = i - n + 1;
        for (int j = 1; j <= n; ++j) {
            bool flag = true;
            for (int k = 0; k < n; ++k) {
                int ti = ii;
                flag &= chk[ii + j + k][ti % n][(ti + cnt[k] - 1) % n];
            }
            for (int k = n; k < n * 2 - 1; ++k) {
                int ti = ii + k - n + 1;
                flag &= chk[ii + j + k][ti % n][(ti + cnt[k] - 1) % n];
            }
            ans += flag;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    enter();
    solve();
    cout << ans << "\n";
    return 0;
}