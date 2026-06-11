#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define s(x, n) memset(x, n, sizeof(x));
#define pb(x) push_back(x)
#define NIL -1
#define MAXN 11

void solve()
{
    int n, k;
    cin >> n >> k;
    int arr[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    bool dp[k + 1];
    s(dp, false);
    for (int i = 0; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i - arr[j] >= 0 && !dp[i - arr[j]])
            {
                dp[i] = true;
            }
        }
    }
    cout << (dp[k] ? "First" : "Second")
         << "\n";
}
int main()
{
#ifdef WIN32
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

#ifndef WIN32
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    int t;
    t = 1;
    /// cin >> t;
    for (int I = 1; I <= t; I++)
    {
        solve();
    }
    return 0;
}