#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
    int N, C;
    cin >> N >> C;
    vector<vi> D(C, vi(C));
    rep(i, C) {
        rep(j, C) {
            cin >> D[i][j];
        }
    }
    vector<vi> A(N, vi(N));
    rep(i, N) {
        rep(j, N) {
            cin >> A[i][j];
            A[i][j]--;
        }
    }

    vector<vi> m(3, vi(C));
    rep(i, N) {
        rep(j, N) {
            m[(i + j) % 3][A[i][j]]++;
        }
    }

    int diff = __INT32_MAX__;
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < C; j++) {
            if (i == j) continue;
            for (int k = 0; k < C; k++) {
                if (i == k || j == k) continue;

                // 色aを色iに塗り替える
                int acnt = 0;
                for (int a = 0; a < C; a++) {
                    // 既に塗られている場合
                    if (i == a) continue;
                    // 塗り替える個数 * 塗り替えるコスト
                    acnt += m[0][a] * D[a][i];
                }

                // 色jを色bに塗り替える
                int bcnt = 0;
                for (int b = 0; b < C; b++) {
                    // 既に塗られている場合
                    if (j == b) continue;
                    // 塗り替える個数 * 塗り替えるコスト
                    bcnt += m[1][b] * D[b][j];
                }

                // 色kを色cに塗り替える
                int ccnt = 0;
                for (int c = 0; c < C; c++) {
                    // 既に塗られている場合
                    if (k == c) continue;
                    // 塗り替える個数 * 塗り替えるコスト
                    ccnt += m[2][c] * D[c][k];
                }
// cout << "i: " << i << ", j:  " << j << ", k: " << k << endl;
// cout << "acnt: " << acnt << ", bcnt: " << bcnt << ", ccnt: " << ccnt << endl;
                diff = min(diff, acnt + bcnt + ccnt);
            }
        }
    }
    cout << diff << endl;
}