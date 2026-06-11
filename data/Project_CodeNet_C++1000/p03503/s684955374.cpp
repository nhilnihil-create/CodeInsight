#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define F first
#define S second
#define MAXN   1000005
#define Tsetso ios_base::sync_with_stdio(0) ; cin.tie(0) ;
using namespace std;
const int N = 120, mod = 998244353 ;
int n, F[N][12], P[N][12];
int main()
{
    Tsetso ;
    cin >> n;
    for ( int i = 0 ; i < n ; i++)
        for ( int j = 0 ; j < 10 ; j++)
            cin >> F[i][j];
    for ( int i = 0 ; i < n ; i++)
        for ( int j = 0 ; j <= 10 ; j++)
            cin >> P[i][j];
    int  ans = -1e9 ;
    for ( int msk = 1 ; msk < (1<<10); msk++)
    {
        int res = 0;
        for ( int i = 0 ; i < n ; i++)
        {
            int cnt = 0 ;
            for ( int j = 0 ; j < 10 ; j++)
                if ( F[i][j] && (msk & (1<<j)))
                        cnt++ ;
            res += P[i][cnt];
        }
        ans = max(ans,res);
    }
    cout << ans;
}
