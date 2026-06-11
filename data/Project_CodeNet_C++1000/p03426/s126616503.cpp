#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;
int main() {
    int H, W, D, Q;
    cin >> H >> W >> D;
    vector<pair<int, int>> vp(H * W);
    vector<int> d(H * W, 0);
    for (int i = 0; i < H; i++) for (int j = 0, A; j < W; j++) {
        cin >> A;
        vp[A - 1] = make_pair(i, j);
    }
    for (int i = D; i < H * W; i++) d[i] = d[i - D] + abs(vp[i].first - vp[i - D].first) + abs(vp[i].second - vp[i - D].second);
    cin >> Q;
    for (int i = 0, L, R; i < Q; i++) {
        cin >> L >> R;
        cout <<d[R - 1] - d[L - 1] << endl;
    }
}