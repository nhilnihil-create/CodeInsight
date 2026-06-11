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
#define off 2

using namespace __gnu_pbds;
using namespace std ;

typedef tree< i64, null_type, less<i64>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef pair<i64, i64> pii;

#define maxn 20000000

vector <i64> v ;

int d(i64 x)
{
    int sum = 0 ;
    while(x!=0)
    {
        sum += x%10 ;
        x /=10 ;
    }
    return sum ;
}

int main()
{
    i64 i , j , k , last , dist ;

    v.pb(1) ;

    last = 1 ; dist = 1 ;

    while( last <1000000000000000 )
    {
        last = v[ (int)v.size() - 1 ] ;
        i64 cur = last + dist ;

        if( last*d(cur) > cur*d(last) )
        {
            dist *= 10 ;
            v.pop_back() ;
            continue ;
        }
        else v.pb(cur) ;
        last = cur ;
    }

  //  for(i=0 ; i<v.size() ; i++) printf("%lld: %lld\n",i+1,v[i]) ;

    scanf("%lld",&k) ;

    for(i=0 ; i<k ; i++) printf("%lld\n",v[i]) ;

    return 0 ;
}
