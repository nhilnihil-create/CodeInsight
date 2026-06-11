#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define repr(i, n) for (int i = (n); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for (int i = x; i < n; i++)
#define OP(m) cout << m << endl
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int main()
{
    int n, m;
    cin >> n >> m;
    int cost[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    int num[m];
    rep(i, m) cin >> num[i];
    string dp[n + 1];
    dp[0] = "";

    for (int i = 1; i <= n; i++)
    {
        dp[i] = "";
        rep(j, m)
        {
            int t = i - cost[num[j]];
            if (t < 0 || (t != 0 && dp[t] == ""))
                continue;
            if (dp[i].size() < dp[t].size() + 1)
                dp[i] = dp[t] + to_string(num[j]);
            else if (dp[i].size() == dp[t].size() + 1)
                dp[i] = max(dp[i], dp[t] + to_string(num[j]));
        }
    }

    OP(dp[n]);

    return 0;
}
