#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using pii = pair<int, int>;

int D[32][32];

int main() {
    int N, C;
    cin >> N >> C;

    rep(i, C) rep(j, C) cin >> D[i+1][j+1];

    int ci, cnt_gr0[C+1], cnt_gr1[C+1], cnt_gr2[C+1];
    rep(i, C+1) cnt_gr0[i] = 0, cnt_gr1[i] = 0, cnt_gr2[i] = 0;

    rep(y, N) rep(x, N) {
        cin >> ci;
        if ((x+1 + y+1)%3 == 0) cnt_gr0[ci]++;
        if ((x+1 + y+1)%3 == 1) cnt_gr1[ci]++;
        if ((x+1 + y+1)%3 == 2) cnt_gr2[ci]++;
    }

    int cost_gr0[C+1], cost_gr1[C+1], cost_gr2[C+1];
    rep(i, C+1) cost_gr0[i] = 0, cost_gr1[i] = 0, cost_gr2[i] = 0;

    rep(x, C) rep(y, C) {
        cost_gr0[y+1] += cnt_gr0[x+1] * D[x+1][y+1];
        cost_gr1[y+1] += cnt_gr1[x+1] * D[x+1][y+1];
        cost_gr2[y+1] += cnt_gr2[x+1] * D[x+1][y+1];
    }

    int ans = 500 * 500 * 1000;
    rep(x, C) rep(y, C) rep(z, C) {
        if ((x==y) || (y==z) || (z==x)) continue;
        ans = min(ans, cost_gr0[x+1] + cost_gr1[y+1] + cost_gr2[z+1]);
    }

    cout << ans << endl;

    return 0;
}

 