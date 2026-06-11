#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
#define int long long

int manhattan(pair<int, int> x, pair<int, int> y) {
    return abs(x.first - y.first) + abs(x.second - y.second);
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int h, w, d;
    cin >> h >> w >> d;

    map<int, pair<int, int>> valpos;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int aij;
            cin >> aij;
            valpos[aij] = {i, j};
        }
    }

    // costs[i]: 駒を問題の手順でi%d から iまで瞬間移動させるのに必要な魔力
    vector<int> costs(h * w + 1);

    for (int i = 1; i <= d; i++) {
        int x = i;
        costs[x] = 0;
        while (x + d <= h * w) {
            pair<int, int> pos = valpos[x], nextpos = valpos[x + d];
            const int cost = manhattan(pos, nextpos);

            costs[x + d] = costs[x] + cost;
            x += d;
        }
    }

    int q;
    cin >> q;
    for (int qi = 0; qi < q; qi++) {
        int l, r;
        cin >> l >> r;

        const int cost = costs[r] - costs[l];

        cout << cost << endl;
    }
}
