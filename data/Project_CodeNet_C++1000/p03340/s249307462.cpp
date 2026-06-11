#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int N = 200005;

int a[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    LL ans = 0, tot = 0;
    for (int i = 1, j = 1; i <= n; i++)
    {
        for (; (a[j] ^ tot) == (a[j] + tot) && (j <= n); j++)
            tot ^= a[j];
        ans += j - i;
        tot ^= a[i];
    }
    printf("%lld\n", ans);
    return 0;
}