#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int H, W, D; cin >> H >> W >> D;
    map<int, pair<int,int>> M;
    int x = 1, y = 1;
    rep(i, H*W) {
        int j; cin >> j;
        M[j] = make_pair(x,y);
        if (++x > W) ++y, x = 1;
    }
    vector MW(H*W+1, 0);
    for (int i = 1; i <= D; i++) {
        pair p = M[i];
        MW[i] = 0;
        for (int j = i+D; j <= H*W; j+=D) {
            pair q = M[j];
            int ma = abs(p.first - q.first) + abs(p.second - q.second);
            MW[j] = MW[j-D] + ma;
            p = q;
        }
    }
    int Q; cin >> Q;
    rep(i, Q) {
        ll ma = 0;
        int L,R; cin >> L >> R;
        ma += MW[R] - MW[L];
        cout << ma << endl;
    }
}
