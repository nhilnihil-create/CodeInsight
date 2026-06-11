#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int64_t> a(n), b(n);
    for (auto &i : a)
    {
        cin >> i;
    }
    for (auto &i : b)
    {
        cin >> i;
    }
    int64_t ans = 0;
    for (int k = 0; k <= 28; k++)
    {
        vector<int64_t> c(a), d(b);
        int64_t t = 1ll << k, num = 0;
        for (int i = 0; i < n; i++)
        {
            c[i] %= (1ll << (k + 1));
            d[i] %= (1ll << (k + 1));
        }
        sort(d.begin(), d.end());
        for (auto &i : c)
        {
            num += distance(d.begin(), lower_bound(d.begin(), d.end(), 2 * t - i));
            num -= distance(d.begin(), lower_bound(d.begin(), d.end(), t - i));
            num += distance(d.begin(), lower_bound(d.begin(), d.end(), 4 * t - i));
            num -= distance(d.begin(), lower_bound(d.begin(), d.end(), 3 * t - i));
        }
        if (num & 1)
        {
            ans += t;
        }
    }
    cout << ans << endl;
    return 0;
}