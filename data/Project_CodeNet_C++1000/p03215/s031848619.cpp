#include "bits/stdc++.h"

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<long> as(n), xs;
    for (int i = 0; i < n; i++)
    {
        cin >> as[i];
    }
    for (int l = 0; l < n; l++)
    {
        long x = 0;
        for (int r = l; r < n; r++)
        {
            x += as[r];
            xs.push_back(x);
        }
    }
    long ans = 0;
    for (int i = 50; i >= 0; i--)
    {
        int cnt = 0;
        vector<long> ys;
        for (long x : xs)
        {
            if (x >> i & 1)
            {
                cnt++;
                ys.push_back(x);
            }
        }
        if (cnt >= k)
        {
            ans |= 1L << i;
            swap(xs, ys);
        }
    }
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}
