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
#define INF 1000000000000000000LL
#define i64 long long int
#define eps (1e-8)
#define xx first
#define yy second
#define ln 20
#define off 2
#define sq(x) ((x)*(x))

using namespace __gnu_pbds;
using namespace std ;

typedef tree< i64, null_type, less<i64>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define maxn 200005

vector <int> g[maxn] ;
char s[maxn] ;
int col[maxn] ;
int ad[maxn][2] ;
bool isDead[maxn] ;

int main()
{
    int i , j , k , l , m , n ;

    scanf("%d %d",&n,&m) ;
    scanf("%s",s+1) ;

    for(i=1 ; i<=n ; i++)
    {
        if( s[i]=='A' ) col[i] = 0 ;
        else col[i] = 1 ;
    }

    queue <int> q ;

    for(i=1 ; i<=m ; i++)
    {
        int u , v ;
        scanf("%d %d",&u,&v) ;
        ad[ u ][ col[v] ]++ ;
        if(u!=v) ad[ v ][ col[u] ]++ ;
        g[u].pb(v) ;
        if(u!=v) g[v].pb(u) ;
    }

    for(i=1 ; i<=n ; i++)
    {
        if( ad[i][0]==0 || ad[i][1]==0  )
        {
            isDead[i] = 1 ;
            q.push(i) ;
        }
    }

    int dead = 0 ;

    while(!q.empty())
    {
        int u = q.front() ;
   //     printf("%d\n",u) ;
        q.pop() ;
        dead++ ;
        isDead[u] = 1 ;

        for(i=0 ; i<g[u].size() ; i++)
        {
            if( isDead[ g[u][i] ] ) continue ;
            ad[ g[u][i] ][ col[u] ]-- ;
            if( !ad[ g[u][i] ][0] || !ad[ g[u][i] ][1] )
            {
                isDead[ g[u][i] ] = 1 ;
                q.push(g[u][i]) ;
            }
        }
    }

    if( dead==n ) printf("No\n") ;
    else printf("Yes\n") ;

    return 0 ;
}
