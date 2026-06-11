#include <bits/stdc++.h>
#define filename "candies"
#define int long long
#define mod 1000000007
#define N 105
#define K 100005

using namespace std ;

int n , k ;
int f[N][K] ;
int a[N] ;

void open()
{
    //freopen(filename".inp","r",stdin) ;
    //freopen(filename".out","w",stdout) ;
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ;
    cout.tie(0) ;
}
void readin()
{
    cin >> n >> k ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i] ;
}
int calc(int n , int k)
{
    f[0][0] = 1 ;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= k ; j++)
        {
            f[i-1][j] += f[i-1][j-1] ;
            f[i-1][j] = f[i-1][j] % mod ;
        }
        for (int j = 0 ; j <= k ; j++)
        {
            f[i][j] = (j > a[i]) ? (f[i-1][j] - f[i-1][j-a[i]-1] + mod) % mod : f[i-1][j] ;
        }
    }
    return f[n][k] ;
}
signed main()
{
    open() ;
    readin() ;
    cout << calc(n , k) ;
}
