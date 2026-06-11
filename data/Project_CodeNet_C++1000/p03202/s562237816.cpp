#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define mod 998244353LL
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
#define off 2

using namespace __gnu_pbds;
using namespace std ;

typedef tree< i64, null_type, less<i64>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef pair<i64, i64> pii;

#define maxn 1000005

vector < pair<int,int> > vp ;
int a[maxn] ;

bool isPossible( int c , int n )
{
 //   printf("--------------------%d\n",c) ;
    int sz = 0 ;
    vp.clear() ;
    vp.pb( mp(1,0) ) ;
    for(int i=1 ; i<=n ; i++)
    {
        if( a[i] > sz )
        {
            pair<int,int> p = vp.back() ;
            if( vp.back().xx==1 ) vp.back().yy += (a[i]-sz) ;
            else vp.pb( mp(1 , a[i]-sz) ) ;
            sz  = a[i] ;
        }
        else{
            while( sz > a[i] )
            {
                if( sz - vp.back().yy >= a[i]  )
                {
                    sz -= vp.back().yy ;
                    vp.pop_back() ;
                }
                else{
                    vp.back().yy -= ( sz-a[i] ) ;
                    sz -= (sz-a[i]) ;
                }
            }
            int last = vp.back().xx ;
            sz -= vp.back().yy ;
            vp.pop_back();

            if( last == c )
            {
                if( vp.empty() )
                {
                    return false ;
                }
                else{
                    last = vp.back().xx ;
                    if( vp.back().yy==1 )
                    {
                        vp.pop_back() ;
                        if( !vp.empty() && vp.back().xx==last+1 ) vp.back().yy++ ;
                        else{
                            vp.pb( mp(last+1,1) ) ;
                        }
                    }
                    else{
                        int sz1 = vp.back().yy ;
                        vp.pop_back() ;
                        vp.pb( mp(last , sz1-1) ) ;
                        vp.pb( mp(last+1,1) ) ;
                    }
                    vp.pb( mp(1,a[i]-sz) ) ;
                    sz = a[i] ;
                }
            }
            else{
                if( sz+1 < a[i] )
                {
                    vp.pb( mp(last , a[i]-sz-1) ) ;
                    vp.pb( mp(last+1, 1) ) ;
                }
                else{
                    if( !vp.empty() && vp.back().xx==last+1 ) vp.back().yy++ ;
                    else vp.pb( mp(last+1,1) ) ;
                }
                sz = a[i] ;
            }
        }
   /*     for(int j=0 ; j<vp.size() ; j++)
        {
            for(int k=0 ; k<vp[j].yy ; k++) printf("%d",vp[j].xx) ;
        }
        printf("\n") ; */
    }
    return true ;
}

int main()
{
    int i , j , k , l , m , n ;

    scanf("%d",&n) ;
    for(i=1 ; i<=n ; i++)
    {
        scanf("%d",&a[i] ) ;
    }

    int lo = 1 , hi = n ;

    while( lo<hi )
    {
        m = (lo+hi)/2 ;
        if( isPossible(m,n) ) hi = m ;
        else lo = m+1 ;
    }

    isPossible(lo,n) ;

    printf("%d\n",lo) ;

    return 0 ;
}
