#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;
    vector<string> s(N);
    rep(i, N) cin >> s[i];
    int cntA = 0, cntB = 0, cntAB = 0, cntBA = 0;
    rep(i, N) {
        int M = s[i].size();
        if (s[i][0] == 'B') ++cntB;
        if (s[i][M - 1] == 'A') ++cntA;
        if (s[i][0] == 'B' && s[i][M - 1] == 'A') ++cntBA;

        rep(j, M) {
            if (s[i][j] == 'A') {
                if (j + 1 < M && s[i][j + 1] == 'B') ++cntAB;
            }
        }
    }

    ll ans = cntAB + min(cntA, cntB);
    if (cntBA != 0 && max(cntA, cntB) == cntBA) --ans;

    cout << ans << endl;
}