#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

int main() {
    // dpx[i][j] Xの番で一番上がa[i]で相手がa[j]を持っているときの最終スコア
    // dpy[i][j] Yの番で一番上がa[i]で相手がa[j]を持っているときの最終スコア
    // dpx[i][j] = max(dpx[i + 1][j], dpy[i + 1][i])
    // dpy[i][j] = min(dpy[i + 1][j], dpx[i + 1][i])
    // A[0] = Z, A[1] = Wとしてdpx[2][1]が答
    // dpx[N + 1][j] = abs(A[N + 1] - A[j]);
    // dpy[N + 1][j] = abs(A[N + 1] - A[j]);
    int N;
    cin >> N;
    vector<int> A(N + 2);
    rep(i, N + 2) cin >> A[i];
    vector<vector<int>> dpx(N + 2, vector<int>(N + 2)), dpy(N + 2, vector<int>(N + 2));
    rep(j, N + 2) {
        dpx[N + 1][j] = abs(A[N + 1] - A[j]);
        dpy[N + 1][j] = abs(A[N + 1] - A[j]);
    }
    for (int i = N; i >= 0; i--) {
        for (int j = N; j >= 0; j--) {
            dpx[i][j] = max(dpx[i + 1][j], dpy[i + 1][i]);
            dpy[i][j] = min(dpy[i + 1][j], dpx[i + 1][i]);
        }
    }
    cout << dpx[2][1] << "\n";
}