#include <bits/stdc++.h>
#define int long long 

using namespace std;

const int maxn = 5000 + 7;

int n, A, B, pos[maxn], dp[maxn], a[maxn], ans;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen("test.inp" ,"r")) freopen("test.inp", "r", stdin);
    cin >> n >> A >> B;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    a[n + 1] = 1e15;
    for(int i = 1; i <= n + 1; i++)
    {
        dp[i] = 1e15;
        ans = 0;
        for(int j = i - 1; j >= 0; j--)
        {
            if(a[j] > a[i]) ans++;
            else
            {
                dp[i] = min(dp[i], dp[j] + ans * A + (i - j - 1 - ans) * B);
            }
        }
    }
    cout << dp[n + 1];
}