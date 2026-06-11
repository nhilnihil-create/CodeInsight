#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>

using namespace std;

bool ok(long long cnt, long long a, long long b)
{
    long long c = a * b;
    if (cnt < b)
    {
        long long F = 1 * cnt;
        long long L = (cnt + 1) * 1;
        long long p1 = cnt / 2;
        for (int i = max(1LL, p1 - 3); i <= min(cnt + 1, p1 + 3); i++)
        {
            long long p2 = 0;
            if (i == a) continue;
            if (i < a) p2 = cnt + 1 - i;
            if (i > a) p2 = cnt + 2 - i;
            if (i * p2 >= c) return 0;
        }
        return 1;
    }
    else
    {
        for (int i = max(1LL, cnt / 2 - 5); i <= min(cnt / 2 + 5, cnt + 1); i++)
        {
            if (i == a) continue;
            long long skipped = i - 1;
            if (i > a) skipped--;
            long long p2 = cnt + 1;
            p2 -= skipped;
            if (p2 <= b) p2--;
            if (i * p2 >= c) return 0;
        }
        return 1;
    }
}

void solve()
{
    long long a, b;
    cin >> a >> b;
    long long c = a * b;
    if (a > b)
        swap(a, b);
    long long l = a - 1, r = 2e9;
    while (l + 1 < r)
    {
        long long mid = (l + r) / 2;
        if (ok(mid, a, b))
            l = mid;
        else
            r = mid;
    }
    cout << l << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) solve();
}
