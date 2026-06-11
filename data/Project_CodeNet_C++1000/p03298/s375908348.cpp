#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <iomanip>
#include <cstring>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())

typedef long long ll;

int main()
{
    int n;
    string s;

    cin >> n >> s;

    ll res = 0;

    for (int i = 0; i < (1 << n); i++)
    {
        string lr = "", lb = "";

        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                lr += s[j];
            else
                lb += s[j];
        }

        ll dp[40][20];
        memset(dp, 0, sizeof(dp));

        dp[n * 2][0] = 1;

        for (int j = n * 2 - 1; j >= n; j--)
        {
            for (int k = 0; k <= lr.size(); k++)
            {
                dp[j][k] += (k > 0) * dp[j + 1][k - 1] * (s[j] == lr[k - 1]);
                dp[j][k] += dp[j + 1][k] * (s[j] == lb[(n * 2 - j) - k - 1]);
            }
        }

        res += dp[n][lr.size()];
    }

    cout << res << endl;

    return 0;
}