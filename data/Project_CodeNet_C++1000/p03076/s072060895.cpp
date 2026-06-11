// https://atcoder.jp/contests/abc123/tasks/abc123_b

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> t(5);
    for (int i = 0; i < 5; i++)
        cin >> t[i];
    sort(t.begin(), t.end(), [](int x, int y) -> bool { return ((x - 1) % 10 < (y - 1) % 10); });

    int ans = t[0];
    for (int i = 1; i < 5; i++)
    {
        ans += (t[i] + 9) / 10 * 10;
    }
    cout << ans << endl;
    return 0;
}
