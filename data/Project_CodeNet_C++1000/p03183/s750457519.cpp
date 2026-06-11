#include <bits/stdc++.h>
using namespace std;
const int N = 1003, m = 10004;
struct ban
{
    int w, s;
    int g;
};
bool operator<(const ban& a, const ban& b)
{
    return a.w + a.s < b.w + b.s;
}

int n;
ban a[N];

long long dp[m];
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d%d", &a[i].w, &a[i].s, &a[i].g);
    sort(a, a + n);
    long long ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = a[i].s; j >= 0; --j)
        {
            ans = max(ans, dp[j] + a[i].g);
            if (j + a[i].w < m)
                dp[j + a[i].w] = max(dp[j + a[i].w], dp[j] + a[i].g);
        }
    }
    cout << ans << endl;
    return 0;
}
