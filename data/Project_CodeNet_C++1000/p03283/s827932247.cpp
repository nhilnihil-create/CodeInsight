#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

int N, M, Q;
int A[550][550];
int acc[550][550];

signed main() {
    cin >> N >> M >> Q;
    rep(i, M) {
        int L, R; cin >> L >> R;
        A[L-1][R-1]++;
    }
    rep(i, N) rep(j, N) acc[i+1][j+1] = acc[i+1][j]+acc[i][j+1]-acc[i][j]+A[i][j];
    while (Q--) {
        int p, q; cin >> p >> q;
        p--;
        q--;
        cout << acc[q+1][q+1]-acc[q+1][p]-acc[p][q+1]+acc[p][p] << endl;
    }
}