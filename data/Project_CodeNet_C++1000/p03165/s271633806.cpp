#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int dp[3009][3009];
string s, t, ans = "";

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> s >> t;

    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = 1; j <= t.size(); j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }

    int n = s.size(), m = t.size();
    while (n > 0 && m > 0)
    {
        if (s[n - 1] == t[m - 1])
        {
            ans += t[m - 1];
            n--;
            m--;
        }
        else
        {
            if (dp[n - 1][m] > dp[n][m - 1])
            {
                n--;
            }
            else
            {
                m--;
            }
        }
    }

    reverse(ans.begin(), ans.end());

    cout << ans << "\n";
}