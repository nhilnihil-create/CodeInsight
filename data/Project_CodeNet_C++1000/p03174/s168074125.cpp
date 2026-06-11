#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define F first
#define S second
#define Tsetso ios_base::sync_with_stdio(0) ; cin.tie(0) ;
using namespace std;
const ll N = 23, inf = 1e3+5, mod = 1e9+7, NN = 1e5+10;
ll n, a[N][N],dp[N][1<<21];
ll solve ( int idx , int msk)
{
    if (idx == n)
            return 1 ;
    if ( dp[idx][msk] != -1)
            return dp[idx][msk];
    ll res = 0 , lol = 1 ;
    for ( int j = 0 ; j < n ; j++)
    {
        if ( a[idx][j] && (msk & lol) == 0 )
            res = (res + solve(idx+1,msk | lol)) %mod;
        lol *= 2;
    }
    return dp[idx][msk] = res ;
}
int main()
{
    cin >> n ;
    for ( int i = 0 ; i < n ; i++)
            for ( int j = 0 ; j < n ; j++)
                    cin >> a[i][j] ;
    memset(dp,-1,sizeof dp);
    cout << solve(0,0);
}

