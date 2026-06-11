#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

int main() {
    int N, Z, W;
    cin >> N >> Z >> W;
    vector<int> a(N + 1, W);
    rep(i, N) cin >> a[i + 1];
    //dpx[i][j]: Xの番で山札上がa[i]でYがa[j]を持ってる時のスコア
    //dpy[i][j]: Yの番で山札上がa[i]でXがa[j]を持ってる時のスコア
    vector<vector<int>> dpx(N + 1, vector<int>(N + 1)), dpy(N + 1, vector<int>(N + 1));
    rep(i, N) {
        dpx[N][i] = abs(a[N] - a[i]);
        dpy[N][i] = abs(a[N] - a[i]);
    }
    for (int i = N - 1; i > 0; i--) {
        rep(j, i) {
            dpx[i][j] = max(dpy[i + 1][i], dpx[i + 1][j]);
            dpy[i][j] = min(dpx[i + 1][i], dpy[i + 1][j]);
        }
    }
    /*
    rep(i, N + 1) {
        rep(j, N + 1) {
            cout << "dpx[" << i << "," << j << "]=" << dpx[i][j];
            cout << " dpy[" << i << "," << j << "]=" << dpx[i][j] << endl;
        }
    }
    */
    cout << dpx[1][0] << endl;
}