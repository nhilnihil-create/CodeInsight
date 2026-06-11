#include <bits/stdc++.h>
using namespace std;
#define NMAX 110000

vector<int> dp(NMAX);

int solve(int n)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int res = n;

    for (int six = 1; six <= n; six *= 6)
        res = min(res, solve(n - six) + 1);

    for (int nine = 1; nine <= n; nine *= 9)
        res = min(res, solve(n - nine) + 1);

    return dp[n] = res;
}

int main()
{
    int n;
    cin >> n;

    dp.assign(NMAX, -1);

    cout << solve(n) << endl;
}