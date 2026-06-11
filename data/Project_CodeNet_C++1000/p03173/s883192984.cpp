#include <bits/stdc++.h>
using namespace std;

const int mxN = 4e2 + 2;
long long n, nums[mxN], dp[mxN][mxN];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            long long s = 0;
            for (int j = i; j < i + len; j++)
            {
                s += nums[j];
            }
            long long ret = 1e15;
            for (int sp = 1; sp <= len - 1; sp++)
            {
                ret = min(ret, dp[i][sp] + dp[i + sp][len - sp]);
            }
            dp[i][len] = ret + s;
        }
    }

    cout << dp[0][n] << endl;
}