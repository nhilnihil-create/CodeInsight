// https://atcoder.jp/contests/abc081/tasks/abc081_b

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 40; // 2^40 > max(a)
    for (int i = 0; i < n; i++)
    {
        long a;
        int cnt = 0;
        cin >> a;
        while (a % 2 == 0)
        {
            a /= 2;
            cnt++;
        }
        ans = min(ans, cnt);
    }

    cout << ans << endl;
    return 0;
}
