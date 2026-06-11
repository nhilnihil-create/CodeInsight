#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for (int i = m; i < n; ++i)

int main() {
    int N; cin >> N;
    vector<string> S(2 * N);
    rep(i, 0, N) {
        cin >> S[i];
        S[i + N] = S[i];
    }
    int ans = 0;
    rep(d, 0, N) {
        bool ok = true;
        rep(i, 0, N) rep(j, 0, N) {
            if(S[i + d][j] != S[j + d][i]) ok = false;
        }
        if(ok) ans += N;
    }
    cout << ans << endl;
    return 0;
}
