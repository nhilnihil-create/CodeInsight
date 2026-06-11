#include <bits/stdc++.h>
#define int long long
const int MOD = 1e9 + 7;
using pii=std::pair<int,int>;
using namespace std;

const int maxn = 21, maxmask = (1ll << 21);

int n, a[maxn][maxn], dp[maxmask];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    dp[0] = 1;
    for(int i = 0; i < (1ll << n); i++)
    {
        int pos = __builtin_popcount(i);
        for(int j = 0; j < n; j++)
            if(!(i & 1ll << j) && a[pos][j])
            {
                dp[i | (1ll << j)] += dp[i];
                dp[i | (1ll << j)] %= MOD;
            }
    }
    cout << dp[(1ll << n) - 1] << "\n";
    return 0;
}