#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int h, w, n;
vector<int> all_x[max_n];
set<pair<int, int>> all;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &h, &w, &n);
    for (int i = 0; i < w; ++i) {
        all_x[i].push_back(h);
        all.insert({h, i});
    }
    for (int i = 0; i < h; ++i) {
        all.insert({i, w});
    }
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x;
        --y;
        all.insert({x, y});
        all_x[y].push_back(x);
    }
    for (int i = 0; i < w; ++i) {
        sort(all_x[i].begin(), all_x[i].end());
    }
    int x = 0, y = 0, ans = h, cur = 0;
    while (true) {
        int mn = *upper_bound(all_x[y].begin(), all_x[y].end(), x);
        //cout << x << " " << y << " " << cur << " " << mn << ": " << cur + mn - x << endl;
        ans = min(ans, cur + mn - x);
        if (all.count({x + 1, y})) {
            break;
        }
        ++x;
        if (!all.count({x, y + 1})) {
            ++y;
        }
        ++cur;
    }
    printf("%d\n", ans);
    return 0;
}
