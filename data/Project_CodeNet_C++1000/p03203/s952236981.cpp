#include <bits/stdc++.h>
using namespace std;

constexpr int inf = 1e9;

int main() {
    int h, w, n; cin >> h >> w >> n;
    vector<vector<int>> xs(w, vector<int>(1, h + 1));
    for(int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        xs[y - 1].push_back(x);
    }
    for(auto& xx : xs) sort(xx.begin(), xx.end());

    auto dist = [&] (int x, int y) {
        return *upper_bound(xs[y].begin(), xs[y].end(), x) - x;
    };

    auto find_hole = [&] (int x, int y) {
        if(y + 1 == w) return -1;
        int res = -1;
        while(x < h) {
            const int nx = *lower_bound(xs[y + 1].begin(), xs[y + 1].end(), x + 1);
            if(nx > x + 1) {
                res = x + 1;
                break;
            }
            x = nx;
        }
        return res;
    };

    int ans = inf, x = 1;
    for(int y = 0; y < w; ++y) {
        const int d = dist(x, y);
        ans = min(ans, x + d - 1);
        if(y + 1 != w) {
            const int hole = find_hole(x, y);
            if(hole == -1) {
                break;
            }
            x = hole;
        }
    }

    cout << ans << endl;
}
