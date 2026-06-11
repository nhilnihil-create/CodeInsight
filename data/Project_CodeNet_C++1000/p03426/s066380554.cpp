#include <bits/stdc++.h>
using namespace std;

#define REP(i, start, count) for(int i=(start); i<(int)(count); ++i)
#define rep(i, count) REP(i, 0, count)
#define ALLOF(c) (c).begin(), (c).end()

typedef long long ll;
typedef unsigned long long ull;

int H, W, D;
vector<pair<int, int>> A;
int Q;

int main(void) {
    cin >> H >> W >> D;
    A.resize(H * W + 1);
    // 5回WA
    // なんか走査のX,Yが逆になってた
    REP(y, 0, H) {
        REP(x, 0, W) {
            int a;
            cin >> a;
            A[a] = pair<int, int>(x, y);
        }
    }

    int d[90001] = {};
    for(int i = D + 1; i <= H * W; ++i) {
        d[i] = d[i - D] + abs(A[i].first - A[i - D].first) + abs(A[i].second - A[i - D].second);
    }

    cin >> Q;
    rep(i, Q) {
        int L, R;
        cin >> L >> R;
        cout << (d[R] - d[L]) << endl;
    }

    return 0;
}