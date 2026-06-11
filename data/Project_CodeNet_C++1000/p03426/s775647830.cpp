#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int H, W, D;
    cin >> H >> W >> D;
    vector<pair<int, int>> pos(H * W + 1);

    rep(i, H) rep(j, W)
    {
        int A;
        cin >> A;
        pos[A] = make_pair(i + 1, j + 1);
    }

    vector<int> cost(H * W + 1, 0);
    for (int n = 1; n <= H * W; n++)
    {
        int next = n + D;
        if (next > H * W)
            continue;
        int move_cost = abs(pos[n].first - pos[next].first) + abs(pos[n].second - pos[next].second);
        cost[next] = cost[n] + move_cost;
    }

    int Q;
    cin >> Q;
    vector<int> ans(Q);
    rep(i, Q)
    {
        int L, R;
        cin >> L >> R;
        ans[i] = cost[R] - cost[L];
    }
    rep(i, Q)
    {
        cout << ans[i] << endl;
    }
    return 0;
}