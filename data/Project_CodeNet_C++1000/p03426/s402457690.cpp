#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;

int main() {
    int H, W, D, tmp; cin >> H >> W >> D;
    vector<pair<int, int>> pos(H*W+1);
    rep(i, H)rep(j, W) {
        cin >> tmp;;
        pos[tmp] = make_pair(i, j);
    }
    vector<int> cost(H*W+1);
    for (int i = D+1; i <= H*W; i++) {
        cost[i] = cost[i-D] + abs(pos[i].first-pos[i-D].first) + abs(pos[i].second-pos[i-D].second);
    }
    int Q; cin >> Q;
    int L, R;
    rep(i, Q) {
        cin >> L >> R;
        cout << cost[R] - cost[L] << endl;
    }
}
