#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int MOD = 1e9 + 7;

string s;
long long k;

long long dp[301][301][301];
int n;

int main()
{
    cin >> s;
    cin >> k;
    n = s.size();
    long long as = 0;
    for (int i = 0; i < n; i++)
    {
        if (i > 0) dp[i][i - 1][0] = 0;
        dp[i][i][0] = 1;
        as = max(as, 1LL);
    }
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i + len - 1 < n; i++)
        {
            int j = i + len - 1;
            for (int e = 0; e <= k; e++)
            {
                if (s[i] == s[j])
                {
                    dp[i][j][e] = max(dp[i][j][e], dp[i + 1][j - 1][e] + 2);
                }
                else
                {
                    if (e - 1 >= 0)
                        dp[i][j][e] = max(dp[i][j][e], dp[i + 1][j - 1][e - 1] + 2);
                }
                dp[i][j][e] = max(dp[i][j][e], dp[i][j - 1][e]);
                dp[i][j][e] = max(dp[i][j][e], dp[i + 1][j][e]);
                as = max(as, dp[i][j][e]);
            }
        }
    }
    cout << as;
}
