#include "bits/stdc++.h"

using namespace std;

void Main() {
    int H, W, D;
    cin >> H >> W >> D;
    map<int, pair<int, int>> A;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            int a;
            cin >> a;
            A.insert(make_pair(a, make_pair(i, j)));
        }
    }

    int HW = H * W;
    map<int, vector<int>> accums;
    for (int i = 0; i < D; ++i) {
        vector<int> acc;
        acc.push_back(0);
        int curr = (i == 0 ? D : i);
        int next = i + D;
        while (next <= HW) {
            auto currA = A[curr];
            auto nextA = A[next];
            int cost = abs(currA.first - nextA.first) + abs(currA.second - nextA.second);
            acc.push_back(acc.back() + cost);
            curr = next;
            next += D;
        }
        accums.insert(make_pair(i, acc));
    }

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; ++q) {
        int l, r;
        cin >> l >> r;

        const vector<int>& acc = accums[l % D];
        int ans = acc[r / D] - acc[l / D];
        cout << ans << endl;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
