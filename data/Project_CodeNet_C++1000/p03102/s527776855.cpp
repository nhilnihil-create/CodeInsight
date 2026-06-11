// https://atcoder.jp/contests/abc121/tasks/abc121_b

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, c;
    cin >> n >> m >> c;

    vector<int> b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        long s = c;
        for (int j = 0; j < m; j++)
        {
            int a_j;
            cin >> a_j;
            s += a_j * b[j];
        }
        ans += int(s > 0);
    }
    cout << ans << endl;
    return 0;
}
