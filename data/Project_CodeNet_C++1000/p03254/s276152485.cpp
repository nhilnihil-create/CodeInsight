// https://atcoder.jp/contests/agc027/tasks/agc027_a

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long x;
    cin >> n >> x;

    vector<long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (x - a[i] >= 0)
        {
            ++ans;
            x -= a[i];
        }
        else
        {
            break;
        }
    }
    if (x - a[n - 1] == 0)
    {
        ++ans;
    }
    cout << ans << endl;
    return 0;
}
