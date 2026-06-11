#include <bits/stdc++.h>

using namespace std;

const int MaxN = 2e5 + 25;

int n, X;
int a[MaxN];

long long f(int k)
{
    long long res = 0;
    for(int i = n - k + 1; i <= n; ++i)
        res += a[i];

    for(int i = 1; i <= (n - 1) / k + 1; ++i)
    {
        int r = n - (i - 1) * k;
        int l = r - k + 1;
        if(l < 1)
            l = 1;

        for(int j = l; j <= r; ++j)
        {
            int len = a[j];
            if(j - k > 0)
                len -= a[j - k];
            res += (long long) (1 + i) * (1 + i) * len;
        }
    }
    return res + (long long) X * (n + k);
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
//    freopen("input.txt", "r", stdin);

    cin >> n >> X;

    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    int l = 1;
    int r = n;

    long long ans = 1e18;

    while(r - l > 2)
    {
        int t = (r - l) / 3;

        int p1 = l + t;
        int p2 = r - t;

        long long k1 = f(p1);
        long long k2 = f(p2);

        if(f(p1) < f(p2))
            r = p2 - 1;
        else
            l = p1 + 1;

        ans = min(ans, min(k1, k2));
    }

    while(l <= r)
        ans = min(ans, f(l++));

    cout << ans << '\n';

    return 0;
}
