#include <bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define int long long

const int N = 1010;

int a[N], sum[N * N];
bool chk[N * N];

signed main()
{
    fastio;
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    int ptr = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; ++j)
            sum[ptr++] = a[j] - a[i - 1];

    int ans = 0;
    for (int x = 42; x >= 0; --x)
    {
        int cnt = 0;
        for (int i = 1; i < ptr; ++i)
        {
            if (!chk[i] && ((sum[i] >> x) & 1))
            {
                ++cnt;
            }
        }
        if (cnt >= k)
        {
            ans ^= (1ll << x);
            for (int i = 1; i < ptr; ++i)
            {
                if (!((sum[i] >> x) & 1))
                    chk[i] = true;
            }
        }
    }
    cout << ans;
    return 0;
}

/* input

*/