#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> L(m), R(m);
    rep(i, m) {
        cin >> L[i] >> R[i];
    }
    vector<int> P(q), Q(q);
    rep(i, q) {
        cin >> P[i] >> Q[i];
    }

    const int N_MAX = 505;
    vector<vector<int>> M(N_MAX, vector<int>(N_MAX));
    rep(i, m) {
        M[L[i]][R[i]]++;
    }

    // 2次元累積和
    for (int i = 1; i < N_MAX; i++) {
        for (int j = 1; j < N_MAX; j++) {
            M[i][j] += M[i - 1][j];
            M[i][j] += M[i][j - 1];
            M[i][j] -= M[i - 1][j - 1];
        }
    }

    rep(i, q) {
        int x = P[i]; int y = Q[i];
        cout << M[y][y] - M[x - 1][y] - M[y][x - 1] + M[x - 1][x - 1] << endl;
    }
}