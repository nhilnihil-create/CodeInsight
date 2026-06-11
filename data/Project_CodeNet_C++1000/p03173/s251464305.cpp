#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

ll dp[409][409], sum[409][409];
ll a[409];
int N;

ll solve(int l, int r)
{
    if (dp[l][r] != -1) return dp[l][r];

    if (l == r) return dp[l][r] = 0;

    ll mn = 1e18;
    for (int i = l; i < r; i++)
    {
        mn = min(solve(l, i) + solve(i + 1, r) + sum[l][r], mn);
    }

    dp[l][r] = mn;
    return dp[l][r];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++) dp[i][j] = -1;
    }

    ll full = 0;
    for (int i = 1; i <= N; i++)
    {
        full = 0;
        for (int j = i; j <= N; j++)
        {
            full += a[j];
            sum[i][j] = full;
        }
    }

    cout << solve(1, N) << "\n";
}