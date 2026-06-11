#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;

const int MAX = 200;

// input
int H, W;
int c[10][10];
int A[MAX][MAX];


void input() {
    cin >> H >> W;
    rep(i, 10) rep(j, 10) cin >> c[i][j];
    rep(i, H) rep(j, W) cin >> A[i][j];
}


void warshall_floyd() {
    rep(k, 10) rep(i, 10) rep(j, 10) {
        c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
    }
}


int main() {
    input();
    warshall_floyd();
    int ans = 0;
    rep(i, H) rep(j, W) {
        if (A[i][j] !=  -1) ans += c[A[i][j]][1];
    }
    cout << ans << endl;
}
