#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>/
// #include <ext/pb_ds/tree_policy.hpp>

#define pb push_back
#define mp make_pair

#define mod 998244353LL
#define IN freopen("input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,a,b) for(i=a ; i<=b ; i++)
#define DBG printf("Hi\n")
#define INF 1000000000000000000LL
#define i64 long long int
#define eps (1e-8)
#define xx first
#define yy second
#define ln 17
#define off 2
#define SZ(z) ((int)z.size())
#define sq(x) ((x)*(x))

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL)

#define EPS 1e-7

// using namespace __gnu_pbds;
using namespace std ;

// typedef tree< i64, null_type, less<i64>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

typedef pair<i64, i64> pii;

#define maxn (1<<18)+5
#define alpha 22

i64 a[maxn] ;
pair<int,int> dp[maxn] ;
bool vis[maxn] ;

int n ;

void update( pair<int,int> &p , int idx )
{
    if( a[p.xx] < a[p.yy] ) swap( p.xx , p.yy ) ;

    if( p.xx == idx || p.yy == idx ) return ;
    if( a[p.yy] < a[idx]  ) p.yy = idx ;
    if( a[p.xx] < a[p.yy] ) swap( p.xx , p.yy ) ;
}

void dfs(int mask)
{
    if( vis[mask] ) return ;

    dp[mask] = mp( mask  , (1<<n) ) ;

    for(int i=0 ; i<n ; i++)
    {
        if( (mask&(1<<i)) )
        {
            dfs( (mask^(1<<i)) ) ;
            update( dp[mask] , dp[ (mask^(1<<i)) ].xx ) ;
            update( dp[mask] , dp[ (mask^(1<<i)) ].yy ) ;
        }
    }
  //  printf("%d: %d %d\n",mask,dp[mask].xx,dp[mask].yy) ;
    vis[mask] = 1 ;
    return ;
}

i64 ans[maxn] ;

int main()
{
    scanf("%d",&n) ;

    for(int i=0 ; i<(1<<n) ; i++)
    {
        scanf("%d",&a[i]) ;
    }

    a[ (1<<n) ] = -INF ;

    dfs( ((1<<n)-1) ) ;

    for(int i=1 ; i<(1<<n) ; i++)
    {
        ans[i] = a[ dp[i].xx ] + a[ dp[i].yy ] ;
        ans[i] = max( ans[i-1] , ans[i] ) ;
        printf("%lld\n",ans[i]) ;
    }

    return 0 ;
}
