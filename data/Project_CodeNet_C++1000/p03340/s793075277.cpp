#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
#define int long long
int n;
int a[N];
int ans;
int last[N];
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    last[1] = 0;
    for (int i = 2; i <= n; ++i)
    {
        last[i] = i - 1;
        if (a[i] == 0)
        {
            if (a[i - 1] == 0) last[i] = last[i - 1];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        int cursum = 0;
        int curxor = 0;
        int j = i;
        while (j != 0)
        {
            cursum += a[j];
            curxor ^= a[j];
            if (cursum == curxor) ans += j - last[j];
            else break;
            j = last[j];

        }
    }
    cout << ans;

    return 0;
}
