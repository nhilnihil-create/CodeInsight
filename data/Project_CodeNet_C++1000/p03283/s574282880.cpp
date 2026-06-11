#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main() {
    int N, M, Q, l, r;
    cin >> N >> M >> Q;
    vector<vector<int> > a(N+1, vector<int>(N+1));
    for (int i = 0; i < M; ++i) {
        cin >> l >> r;
        a[l][r]++;
    }

    // 二次元累積和
    vector<vector<int> > s(N+2, vector<int>(N+2, 0));
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + a[i][j];

    // クエリ [x1, x2) × [y1, y2) の長方形区域の和
    for (int q = 0; q < Q; ++q) {
        int x, y;
        cin >> x >> y;
        cout << s[y+1][y+1] - s[x][y+1] - s[y+1][x] + s[x][x] << endl;
    }
}