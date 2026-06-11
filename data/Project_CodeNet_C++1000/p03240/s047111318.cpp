#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {
    int N; cin >> N;
    int A[100][3]; rep(i, N) rep(j, 3) cin >> A[i][j];
    rep(i, N) if (A[i][2] != 0) rep(j, 3) swap(A[0][j], A[i][j]);
    rep(cx, 101) rep(cy, 101) {
        bool ok = true;
        int H = A[0][2] + abs(cx - A[0][0]) + abs(cy - A[0][1]);
        if (H < 1) continue;
        rep(i, N)
            if (max(H - abs(cx - A[i][0]) - abs(cy - A[i][1]), 0) != A[i][2])
                ok = false;
        if (ok) cout << cx << " " << cy << " " << H << endl;
    }
    return 0;
}