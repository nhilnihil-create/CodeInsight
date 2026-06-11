#include<bits/stdc++.h>

using namespace std;

int N, A, B, p[5009];
long long dp[5009][5009];
const long long INF = 1LL << 60;

void u (long long &x, long long y)
{
    if (y < x)
        x = y;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &N, &A, &B);
for (int i=1; i<=N; i++)
    scanf ("%d", &p[i]);
for (int i=1; i<=N; i++)
    for (int j=1; j<=N; j++)
        dp[i][j] = INF;
for (int i=N + 1; i>1; i--)
    for (int j=1; j<=N; j++)
    {
        if (p[i - 1] <= j)
            u (dp[i - 1][p[i - 1]], dp[i][j]),
            u (dp[i - 1][j], dp[i][j] + B);
        u (dp[i - 1][min (j, p[i - 1])], dp[i][j] + A);
    }
long long ans = INF;
for (int i=1; i<=N; i++)
    ans = min (ans, dp[1][i]);
printf ("%lld\n", ans);
return 0;
}
