// https://atcoder.jp/contests/abc092/tasks/abc092_b

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, d, x;
    cin >> n >> d >> x;
    int ans = x;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        for (int j = 0; j < d; j += a)
            ans++;
    }

    cout << ans << endl;
    return 0;
}
