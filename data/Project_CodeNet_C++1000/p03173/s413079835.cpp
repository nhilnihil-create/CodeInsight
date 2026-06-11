//thuanqvbn03
#include <bits/stdc++.h>

using namespace std;

const int MaxN = 405;

int n;
int a[MaxN];
long long ps[MaxN], dp[MaxN][MaxN];

long long Cal(int L, int R)
{
    if (L == R)
    {
        return 0;
    }
    if (dp[L][R] != 0)
    {
        return dp[L][R];
    }
    dp[L][R] = 1e18;
    for (int i = L; i < R; i++)
    {
        dp[L][R] = min(dp[L][R], Cal(L, i) + Cal(i + 1, R));
    }
    dp[L][R] += ps[R] - ps[L - 1];
    return dp[L][R];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ps[i] = ps[i - 1] + a[i];
    }
    cout << Cal(1, n);
    return 0;
}