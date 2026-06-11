#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vi L(M), R(M);
    rep(i, M) {
        cin >> L[i] >> R[i];
        // L[i]--; R[i]--;
    }
    vi A(Q), B(Q);
    rep(i, Q) {
        cin >> A[i] >> B[i];
        // A[i]--; B[i]--;
    }

    vector<vector<int>> G(N + 1, vector<int>(N + 1));
    rep(i, M) {
        G[L[i]][R[i]]++;
    }

    // 2次元累積和
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            G[i][j] += G[i][j - 1];
            G[i][j] += G[i - 1][j];
            G[i][j] -= G[i - 1][j - 1];
        }
    }

    rep(i, Q) {
        int p = A[i];
        int q = B[i];
        int res = G[q][q] - G[q][p - 1] - G[p - 1][q] + G[p - 1][p - 1];
        cout << res << endl;
    }
}