#include <bits/stdc++.h>
#define filename "longestpath"
#define int long long
#define N 100005

using namespace std ;

bool chk[N] ;
vector <int> a[N] ;
int f[N] ;
int n ,m ;

void open()
{
    //freopen(filename".inp","r",stdin) ;
    //freopen(filename".out","w",stdout) ;
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ;
    cout.tie(0) ;
}
void readinp()
{
    cin >> n >>m ;
    for (int i = 1 ; i <= m ; i++)
    {
        int x , y ;
        cin >> x >> y ;
        a[x].push_back(y) ;
    }
}
int recall(int x)
{
    if (chk[x]) return f[x] ;
    chk[x] =1 ;
    int &ans = f[x] ;
    ans = 0 ;
    for (int i : a[x]) 
        ans = max(ans , recall(i) + 1) ;
    return ans ;
}
void process()
{
    int res = 0 ;
    for (int i = 1 ; i <= n ; i++)
        res = max(res , recall(i)) ;
    cout << res ;
}
signed main()
{
    open() ;
    readinp() ;
    process() ;
}