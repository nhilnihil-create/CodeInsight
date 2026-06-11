#include <bits/stdc++.h>
#define ll long long
#define ls id << 1
#define rs id << 1 | 1
#define mem(array, value, size, type) memset(array, value, ((size) + 5) * sizeof(type))
#define memarray(array, value) memset(array, value, sizeof(array))
#define pb(x) push_back(x)
#define st(x) (1LL << (x))
#define pii pair<int, int>
#define mp(a, b) make_pair((a), (b))
#define Flush fflush(stdout)
using namespace std;
const int N = 500050;
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f;
const ll mod = 998244353LL;
clock_t TIME_START, TIME_END;
void program_end()
{
#ifdef ONLINE
    printf("\nTime used: %.6lf(s)\n", ((double)TIME_END - TIME_START) / CLOCKS_PER_SEC);
    system("pause");
#endif
}
int n;
ll a[N];

void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    ll mx = a[n];
    if (mx % 2 == 0)
    {
        ll mid = a[n] / 2;
        ll ans2 = a[1], now = llinf;
        for (int i = 1; i <= n; ++i)
        {
            if (abs(a[i] - mid) < now)
            {
                now = abs(a[i] - mid);
                ans2 = a[i];
            }
        }
        printf("%lld %lld\n", mx, ans2);
    }
    else
    {
        ll mid1 = a[n] / 2, mid2 = a[n] / 2 + 1;
        ll ans2 = a[1], now = llinf;
        for (int i = 1; i <= n; ++i)
        {
            if (min(abs(a[i] - mid2), abs(a[i] - mid1)) < now)
            {
                now = min(abs(a[i] - mid2), abs(a[i] - mid1));
                ans2 = a[i];
            }
        }
        printf("%lld %lld\n", mx, ans2);
    }
}

int main()
{
    TIME_START = clock();
    int Test = 1;
    // cin >> Test;
    while (Test--)
        solve();
    TIME_END = clock();
    program_end();
    return 0;
}