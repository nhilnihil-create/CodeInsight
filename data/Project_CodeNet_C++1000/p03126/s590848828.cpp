// https://atcoder.jp/contests/abc118/tasks/abc118_b

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    long mask = (1 << m) - 1;
    for (int i = 0; i < n; i++)
    {
        int k;
        long b = 0;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int a;
            cin >> a;
            b |= 1 << (--a);
        }
        mask &= b;
    }

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        if ((mask >> i) & 1)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
