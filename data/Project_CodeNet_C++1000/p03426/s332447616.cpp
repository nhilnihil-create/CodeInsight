#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using pii = pair<int, int>;

vector<pii> A;

int main() {
    int H, W, D;
    cin >> H >> W >> D;
    
    A.assign(H*W+1, pii(0, 0));
    int ai;
    rep(y, H) rep(x, W) {
        cin >> ai;
        A[ai] = pii(x, y);
    }

    int MP[H * W + 1] = {};
    for (int v=H*W-D; v>=1; v--) {
        int next_v = v + D;
        int abs_x = abs(A[v].first - A[next_v].first);
        int abs_y = abs(A[v].second - A[next_v].second);
        MP[v] = MP[next_v] + abs_x + abs_y;
    }

    int Q, li, ri;
    cin >> Q;
    rep(q, Q) {
        cin >> li >> ri;
        cout << MP[li] - MP[ri] << endl;
    }

    return 0;
}

 