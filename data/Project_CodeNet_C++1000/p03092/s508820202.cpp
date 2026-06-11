#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define IN freopen("dichromatic.in","r",stdin)
#define OUT freopen("dichromatic.out","w",stdout)
#define FOR(i,a,b) for(i=a ; i<=b ; i++)
#define DBG pf("Hi\n")
#define INF 1000000000
#define i64 long long int
#define eps (1e-8)
#define xx first
#define yy second
#define sq(x)  ((x)*(x))

using namespace __gnu_pbds;
using namespace std ;

#define maxn 200005
#define mod 1000000007LL

typedef  long long int T ;

i64 dp[5005][5005] , cnt[5005][5005] , a[5005] ;

int main()
{
    int n ;
    i64 A , B ;

    scanf("%d %lld %lld",&n,&A,&B) ;

    for(int i=1 ; i<=n ; i++) scanf("%lld",&a[i]) ;

    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=n ; j++) cnt[i][j] = cnt[i-1][j] ;
        for(int j=a[i]-1 ; j>=1 ; j--) cnt[i][j]++ ;
    }

    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=n ; j++)
        {
            if( a[i] > j ) dp[i][j] = dp[i-1][j] ;
            else dp[i][j] = min( B+dp[i-1][ j ] , (cnt[i][a[i]]-cnt[i][j])*A + dp[i-1][ a[i] ] ) ;
        }
    }

    printf("%lld\n",dp[n][n]) ;

    return 0 ;
}
