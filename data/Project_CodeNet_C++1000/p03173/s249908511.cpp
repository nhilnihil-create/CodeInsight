#include <bits/stdc++.h>
#define filename "slimes"
#define int long long
#define oo 1e18
#define N 405 

using namespace std ;

int n , a[N] ;
int f[N][N] ;
bool chk[N][N] ;

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
    cin >> n ;
    for (int i =1 ; i <= n ; i++)
    {
        cin >> a[i] ;
        a[i] += a[i-1] ;
    }
}
int calc(int i , int j)
{
    if (chk[i][j]) return f[i][j] ;
    if(i==j) return 0 ;
    chk[i][j] = 1 ;
    int &ans = f[i][j] ;
    int res = a[j] - a[i-1] ;
    int Min = oo ;
    for(int x = i ; x < j ; x++)
    {
        Min = min(Min , calc(i , x) + calc(x+1 , j)) ;
    }
    return ans = res + Min;
}
signed main()
{
    open() ;
    readin() ;
    cout << calc(1 , n) ;
}