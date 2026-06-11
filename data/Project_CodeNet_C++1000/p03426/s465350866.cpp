#include <bits/stdc++.h>
using namespace std;

using P = pair<int, int>;
int H, W, D;
vector<vector<int>> A;
vector<P> idx;
vector<int> cost;

int dist(P p1, P p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int main() {
    cin >> H >> W >> D;
    idx.resize(H * W + 1);
    A.resize(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
            idx[A[i][j]] = P(i, j);
        }
    }

    cost.resize(H * W + 1);
    for (int i = D + 1; i <= H * W; ++i) {
        cost[i] = cost[i - D] + dist(idx[i], idx[i - D]);
    }
    // DUMP(cost);

    int Q;  cin >> Q;
    for (int _ = 0; _ < Q; ++_) {
        int l, r;  cin >> l >> r;
        cout << cost[r] - cost[l] << endl;
    }
}
