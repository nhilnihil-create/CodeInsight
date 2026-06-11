//be name khoda
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define F first
#define S second
#define int long long

const int maxn = 310;
const int mod = 998244353;
const ll inf = 1e18;

ll pw(ll a, ll b)
{
    if(b == 0) return 1;
    ll k = pw(a,b/2); k = (k * k) % mod;
    if(b&1) k = (k * a) % mod;
    return k;
}

int dp[maxn][maxn][maxn], n, K;

signed main()
{
   // ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string ss; cin>> ss >> K; n = ss.size();
    string s = "."; s += ss;

    for(int t = 1; t <= n; t++)
        for(int l = 1; l <= n-t+1; l++)
            for(int k = 0; k <= K; k++)
            {
                int r = l+t-1;

                if(t == 1)
                {
                    dp[l][r][k] = 1;
                    continue;
                }

                if(s[l] == s[r])
                    dp[l][r][k] = dp[l+1][r-1][k] + 2;
                else
                {
                    dp[l][r][k] = max(dp[l+1][r][k], dp[l][r-1][k]);
                    if(k)
                        dp[l][r][k] = max(dp[l][r][k], dp[l+1][r-1][k-1] + 2);
                }
            }
    cout<< dp[1][n][K];
}




