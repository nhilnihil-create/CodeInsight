#include<bits/stdc++.h>

#define int long long
using namespace std;
#define rep(i, n) for(int i=0;i<(n);++i)
typedef pair<int, int> pii;
const int INF = 1l << 60;
#define u_b upper_bound
#define l_b lower_bound

int shortest[200200];
set<int> obj[200200];

signed main() {
    int H, W, N;
    cin >> H >> W >> N;
    rep(i, N) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        obj[y].insert(x);
    }
    shortest[0] = 0;
    for (int y = 1; y < W; ++y) {
        if (shortest[y - 1] == INF) {
            shortest[y] = INF;
            continue;
        }
        for (int j = shortest[y - 1] + 1;; ++j) {
            if (!obj[y].count(j)) {
                shortest[y] = j;
                break;
            }
            if (j > H) {
                shortest[y] = INF;
                break;
            }
        }
    }
    int ans = H;
    for (int y = 0; y < W; ++y) {
        auto ite = obj[y].upper_bound(shortest[y]);
        if (ite == obj[y].end())continue;
        ans = min(ans, *ite);
    }
    cout << ans << endl;
    return 0;
}
