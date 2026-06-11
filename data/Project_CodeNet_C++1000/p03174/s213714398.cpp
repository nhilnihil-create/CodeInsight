#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rep(i,a,b) for(int i=a; i<b; i++)
#define ll long long

const ll mod = 1e9 + 7;

int n;
bool arr[25][25];
ll dp[22][1<<22];

int main()
{
    FASTIO
    memset(dp,0,sizeof(dp));
    cin >> n;
    rep(i,0,n)
    {
        rep(j,0,n) cin >> arr[i][j];
    }
    dp[0][0] = 1;
    rep(i,1,n+1)
    {
        rep(j,0,1<<n)
        {
            if(__builtin_popcount(j) == i-1)
            {
                rep(k,0,n)
                {
                    if(arr[i-1][k] && !(j&(1<<k)))
                        dp[i][j|(1<<k)] = (dp[i][j|(1<<k)]%mod+dp[i-1][j]%mod)%mod;
                }
            }
        }
    }
    cout << dp[n][(1<<n)-1]%mod << "\n";
    return 0;
}