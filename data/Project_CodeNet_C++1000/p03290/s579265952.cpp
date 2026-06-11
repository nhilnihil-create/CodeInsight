#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)

typedef long long Int;

const Int INF = 1e18;

int main() {
    Int D, G;
    cin >> D >> G;
    G /= 100;
    vector<Int> p(D), c(D);
    rep(i,D) {
        cin >> p[i] >> c[i];
        c[i] /= 100;
    }

    Int ans = INF;

    for (int bit = 0; bit <(1<<D); bit++) {
        Int score = 0;
        Int problems = 0;
        rep(i,D) {
            if (bit & (1<<i)) {
                score += (i + 1) * p[i];
                score += c[i];
                problems += p[i];
            }
        }
        if (G <= score) {
            ans = min(ans, problems);
        }
        else if (__builtin_popcount(bit) < D) {
            int j = 0;
            rep1(i,D-1) {
                if (!(bit & (1<<i))) {
                    j = max(j, i);
                }
            }
            Int p_j;
            p_j = (G - score + j) / (j+1);
            if (p_j >= p[j]) continue;
            else {
                problems += p_j;
                ans = min(ans, problems);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
