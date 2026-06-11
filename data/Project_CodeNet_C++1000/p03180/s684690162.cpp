#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, a[20][20], val[100100], f[100000];
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    int tmp = (1 << n);
    for (int mask = 1; mask < tmp; mask++)
    {
        for (int i = 0; i < n; i++)
            if ((mask >> i) & 1)
                for (int j = i + 1; j < n; j++)
                    if ((mask >> j) & 1)
                        val[mask] += a[i][j];
    }
    for (int mask = 1; mask < tmp; mask++)
    {
        f[mask] = max(f[mask], val[mask]);
        for (int preMask = mask; preMask > 0; preMask = (preMask - 1) & mask)
            f[mask] = max(f[mask], f[preMask] + f[(mask ^ preMask)]);
    }
    cout << f[tmp - 1];
}
