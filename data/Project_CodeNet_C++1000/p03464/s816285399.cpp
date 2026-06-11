#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define IN freopen("hard1.txt","r",stdin)
#define OUT freopen("hard1.txt","w",stdout)
#define FOR(i,a,b) for(i=a ; i<=b ; i++)
#define DBG printf("Hi\n")
#define i64 long long int
#define eps (1e-9)
#define xx first
#define yy second
#define ln 17
#define off 1000005
#define FastIO  ios_base::sync_with_stdio(false); cin.tie(NULL)

using namespace __gnu_pbds;
using namespace std ;

typedef tree< i64, null_type, less<i64>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef pair<i64,i64> pii ;

#define maxn 1000005
#define mod 998244353LL
#define lim 1000000000
#define INF 1000000000000000000LL

i64 a[maxn] ;
pair<i64,i64> range[maxn] ;

int main()
{
    int n ;

    scanf("%d",&n) ;
    for(int i=1 ; i<=n ; i++) scanf("%lld",&a[i]) ;

    if(a[n]!=2)
    {
        printf("-1\n") ;
        return 0 ;
    }

    range[n] = mp(1,1) ;

    for(int i=n-1 ; i>=1 ; i--)
    {
        i64 L = a[i+1]*range[i+1].xx , R = a[i+1]*range[i+1].yy + a[i+1] - 1 ;

        if( (R/a[i])*a[i] < L )
        {
            printf("-1\n") ;
            return 0 ;
        }
        range[i] = mp( (L-1)/a[i] + 1 , R/a[i] ) ;
    }

    printf("%lld %lld\n" , range[1].xx*a[1] , range[1].yy*a[1] + a[1] - 1 ) ;

    return 0 ;
}
