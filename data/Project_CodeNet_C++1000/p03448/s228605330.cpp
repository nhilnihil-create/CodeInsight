// https://atcoder.jp/contests/abc087/tasks/abc087_b

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, x;
    cin >> a >> b >> c >> x;

    long ans = 0;
    for (int i = 0; i <= a; i++)
    {
        int s = 500 * i;
        for (int j = 0; j <= b; j++)
        {
            int t = s + 100 * j;
            for (int k = 0; k <= c; k++)
            {
                if (t + 50 * k == x)
                {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
