// https://atcoder.jp/contests/abc094/tasks/abc094_b

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, x;
    cin >> n >> m >> x;

    int l = 0;
    int r = 0;
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        if (a < x)
        {
            l++;
        }
        else
        {
            r++;
        }
    }

    int ans = min(l, r);
    cout << ans << endl;
}
