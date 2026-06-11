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
#define INF 1000000000
#define i64 long long int
#define eps (1e-8)
#define xx first
#define yy second
#define ln 17
#define off 8002

using namespace __gnu_pbds;
using namespace std ;

typedef tree< i64, null_type, less<i64>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef pair<i64, i64> pii;

#define maxn 8005
const int N = 16005 ;

bitset<N> dp ;

bool f( vector <int> moves , int x )
{
  //  printf("--- %d\n",x) ;
    for(int i=0 ; i<N ; i++) dp[i] = 0 ;
    dp[0+off] = 1 ;

    for(int i=0 ; i<moves.size() ; i++)
    {
        dp = (dp<<moves[i])|(dp>>moves[i]) ;
    }
  /*  for(int i=0 ; i<N ; i++)
    {
        if( dp[i] ) printf("%d ",i-off) ;
    }
    printf("\n") ; */
    if( off+x < 0 ||  x+off >= N ) return false ;
    return dp[off+x] ;
}

int main()
{
    char s[maxn] ;
    int n , x , y ;

    scanf("%s %d %d",s,&x,&y) ;

    vector <int> v[2] ;

    n = strlen(s) ;

    int i = 0 ;
    while( i<n && s[i]=='F' ) i++ ;

    x -= i ;

    for( int fl =1 ; i<n  ; i++ , fl^=1)
    {
        int l = i , r = i ;
        while( r+1 < n && s[r+1]=='F' ) r++ ;
        i = r ;
        v[fl].pb( r-l ) ;
    }


    if( f(v[0],x) && f(v[1],y) ) printf("Yes\n") ;
    else printf("No\n") ;

    return 0 ;
}
