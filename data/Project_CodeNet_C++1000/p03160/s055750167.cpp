#include <bits/stdc++.h>
using namespace std;

int dp[100001];

int solve(int a[], int pos, int n)
{
    if (pos == n)
        return (dp[pos] = 0);
    if (dp[pos] != -1)
        return dp[pos];
    if (pos <= n - 2)
        return (dp[pos] = min(solve(a, pos + 1, n) + abs(a[pos] - a[pos - 1]), solve(a, pos + 2, n) + abs(a[pos - 1] - a[pos + 1])));
    else
        return (dp[pos] = abs(a[pos - 1] - a[n - 1]));
}

int main()
{
    int n;
    cin>>n;

    int a[n];
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    cout<<solve(a, 1, n)<<endl;
    return 0;
}