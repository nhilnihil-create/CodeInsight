#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using P = pair<int, int>;

void solve()
{
    int n, Y;
    cin >> n >> Y;
    rep(x, n + 1) rep(y, n + 1)
    {
        int z = n - x - y;
        if (z < 0)
            continue;
        if (Y == 10000 * x + 5000 * y + 1000 * z)
        {
            printf("%d %d %d\n", x, y, z);
            return;
        }
    }
    printf("-1 -1 -1\n");
}

int main()
{
    solve();
    return 0;
}