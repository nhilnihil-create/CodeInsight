#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
long double dp[3009];
long double ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;

    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        long double prob;
        cin >> prob;

        for (int j = i; j >= 0; j--)
        {
            if (j == 0)
            {
                dp[j] = dp[j] * (1.0 - prob);
            }
            else
            {
                dp[j] = dp[j - 1] * prob + dp[j] * (1.0 - prob);
            }
        }
    }

    for (int heads = 0; heads <= n; heads++)
    {
        int tails = n - heads;

        if (heads > tails) ans += dp[heads];
    }

    cout << setprecision(10) << fixed << ans << "\n";
}