#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define mod 1000000007LL
#define IN freopen("C.in","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,a,b) for(i=a ; i<=b ; i++)
#define DBG pf("Hi\n")
#define i64 long long int
#define eps (1e-8)
#define xx first
#define yy second
#define ln 17
#define off 2

using namespace __gnu_pbds;
using namespace std ;

typedef tree< i64, null_type, less<i64>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef pair<i64, i64> pii;

#define maxn 300005
#define INF 20000000000000000LL
#define alpha 26

char s[maxn] ;

i64 dp[maxn][3] , dis[maxn] ;

int main()
{
    int n ;

    scanf("%s",s) ;

    n = strlen(s) ;
    for(int i=n ; i>=1 ; i--) s[i] = s[i-1] ;

    dis[0] = 1 ;

    for(int i=1 ; i<=n ; i++)
    {
        for(int j=0 ; j<3 ; j++) dp[i][j] = dp[i-1][j] ;
        dis[i] = dis[i-1] ;

        if( s[i]=='A' ) dp[i][0] += dis[i-1] ;
        if( s[i]=='B' ) dp[i][1] += dp[i-1][0] ;
        if( s[i]=='C' ) dp[i][2] += dp[i-1][1] ;

        if( s[i]=='?' )
        {
            dp[i][0] = ( 3*dp[i-1][0] + dis[i-1] ) ;
            dp[i][1] = ( 3*dp[i-1][1] + dp[i-1][0] ) ;
            dp[i][2] = ( 3*dp[i-1][2] + dp[i-1][1] ) ;
            dis[i] = (dis[i-1]*3LL)%mod ;
        }
        for(int j=0 ; j<3 ; j++) dp[i][j] %= mod ;

 //       printf("%lld %lld %lld\n",dp[i][0] , dp[i][1] , dp[i][2]) ;
    }

    printf("%lld\n",dp[n][2]) ;

    return 0 ;
}
