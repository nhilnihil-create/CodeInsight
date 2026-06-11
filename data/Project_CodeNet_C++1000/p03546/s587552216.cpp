#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
#define rep2(i,a,n) for (int i = a; i < n; i++)
using namespace std;
int H, W;
int C[10][10];
int A[201][201];

void init() {
    cin >> H >> W;
    rep(i, 10) rep(j, 10) {
        int c; cin >> c;
        C[i][j] = c;
    }
    rep(h, H) rep(w, W) {
        int a; cin >> a;
        A[h][w] = a;
    }

}

void solve() {
    int res = 0;;

    for (int k = 0; k < 10; k++) rep(i, 10) rep(j, 10) {
        C[i][j] = min(C[i][j], C[i][k] + C[k][j]);
    }

    rep(h, H) {
        rep (w, W) {
            if (A[h][w] == -1) continue;
            int from = A[h][w];
            res += C[from][1];
        }
    }


    printf("%d\n", res);
}

int main() {
    init();
    solve();
    return 0;
}
