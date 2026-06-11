#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP0(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define RREP0(i, n) for (int i = (n)-1; i >= 0; --i)
#define REP1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define RREP1(i, n) for (int i = (n); i >= 1; --i)
#define pow10(n) int(1e##n + n)

typedef long long LL;
typedef pair<int, int> P;

const int INTINF = int(1e9) + 1;
const LL LLINF = LL(1e18) + 1;
long double eps = 1.0E-14;

struct pos
{
    int x;
    int y;
};

LL d[90001];

void solve()
{
    int H, W, D;
    cin >> H >> W >> D;
    map<int, pos> num_pos;
    REP1 (i, H)
    {
        REP1 (j, W)
        {
            int A;
            cin >> A;
            num_pos[A] = pos{i, j};
        }
    }

    for (int i = D + 1; i <= H * W; i++)
    {
        pos pL = num_pos[i], pDL = num_pos[i - D];
        d[i] = d[i - D] + abs(pL.x - pDL.x) + abs(pL.y - pDL.y);
    }

    int Q;
    cin >> Q;
    REP1 (_, Q)
    {
        int L, R;
        cin >> L >> R;
        std::cout << d[R] - d[L] << endl;
    }
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(20);
    solve();
    return 0;
}
