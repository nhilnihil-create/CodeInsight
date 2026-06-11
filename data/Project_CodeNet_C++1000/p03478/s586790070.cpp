// https://atcoder.jp/contests/abc083/tasks/abc083_b

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;

    int ans = 0;
    for (int x = 1; x <= n; x++)
    {
        int s = 0;
        int y = x;
        while (y > 0)
        {
            s += y % 10;
            y /= 10;
        }
        if (a <= s & s <= b)
        {
            ans += x;
        }
    }
    cout << ans << endl;
    return 0;
}
