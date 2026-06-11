#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 3e3 + 5, inf = INT_MAX;

int n;
ld dp[N][N], a[N];

ld solve(int i, int heads)
{
    if (i == n)
        return heads > n / 2? 1: 0;
    if (dp[i][heads] != -1)
        return dp[i][heads];
    return dp[i][heads] = solve(i + 1, heads + 1) * a[i] + solve(i + 1, heads) * (1 - a[i]);
}

int main()
{
    //ios::sync_with_stdio(false);cin.tie(nullptr);ios_base::sync_with_stdio(false);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dp[i][j] = -1;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << fixed << setprecision(10) << solve(0, 0);
    return 0;
}