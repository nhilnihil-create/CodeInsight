#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
const int mo = 1e9 + 7;
typedef long long ll;
#define INF 1 << 30
void solve()
{
    int n;
    cin >> n;
    vector<int> t(n), v(n);
    rep(i, n) cin >> t[i];
    rep(i, n) cin >> v[i];
    int T = 0;
    rep(i, n) T += t[i];
    vector<int> ub(2 * T + 1, INF);
    int x = 0;
    rep(i, n) rep(y, t[i])
    {
        ub[x] = min(ub[x], v[i] * 2);
        ub[x + 1] = min(ub[x + 1], v[i] * 2);
        ub[x + 2] = min(ub[x + 2], v[i] * 2);
        x += 2;
    }
    ub[0] = ub[2 * T] = 0;
    rep(x, 2 * T) ub[x + 1] = min(ub[x + 1], ub[x] + 1);
    for (int x = 2 * T; x > 0; x--)
        ub[x - 1] = min(ub[x - 1], ub[x] + 1);
    double ans = 0;
    rep(x, 2 * T) ans += (ub[x] + ub[x + 1]) / 2.0;
    printf("%.5lf\n", ans / 4);
}
main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    solve();
    return 0;
}