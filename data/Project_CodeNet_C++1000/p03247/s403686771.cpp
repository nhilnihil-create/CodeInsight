#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>/
// #include <ext/pb_ds/tree_policy.hpp>

#define pb push_back
#define mp make_pair

#define mod 1000000007LL
#define IN freopen("input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,a,b) for(i=a ; i<=b ; i++)
#define DBG printf("Hi\n")
#define INF 2000000000000000000LL
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

#define maxn 1000005

#define mxPower 30

i64 x[1005] , y[1005] ;

vector <int> f( i64 m , int p )
{
    if(p==-1)
    {
        vector<int> res ;
        return res ;
    }
    vector <int> res ;
    if( (1LL<<p) > m )
    {
        res = f( (1LL<<p)-m , p-1 ) ;
        for(int i=0 ; i<res.size() ; i++) res[i] *= -1 ;
    }
    else{
        res = f( m-(1LL<<p) , p-1 ) ;
    }
    res.pb(1) ;
    return res ;
}

int main()
{
    int n ;

    scanf("%d",&n) ;

    for(int i=1; i<=n ; i++) scanf("%lld %lld",&x[i],&y[i]) ;

    int parity = ((x[1]+y[1])%2+2)%2 ;

    for(int i=2 ; i<=n ; i++)
    {
        if( ((x[i]+y[i])%2 + 2)%2 != parity )
        {
            printf("-1\n") ;
            return 0 ;
        }
    }

    vector <i64> ansPowers ;
    for(int i=0 ; i<=mxPower ; i++) ansPowers.pb( (1LL<<i) ) ;

    if(parity==0)
    {
        for(int i=1 ; i<=n ; i++) x[i]++ ;
        ansPowers.pb(1) ;
    }

    printf("%d\n", (int)ansPowers.size() ) ;
    for(int i=0 ; i<ansPowers.size() ; i++) printf("%lld ",ansPowers[i]) ;
    printf("\n") ;

    for(int i=1 ; i<=n ; i++)
    {
        vector <int> res = f( abs(x[i])+abs(y[i]) , mxPower ) ;
        i64 Y = abs(y[i]) ;

        vector <int> forY ;

        for(int j=0 ; j<=mxPower ; j++)
        {
            if( Y%2 )
            {
                forY.pb(1) ;
                if( res[j]==1 ) Y-- ;
                else Y++ ;
            }
            else{
                forY.pb(0) ;
            }
            Y /= 2 ;
        }
        string ans ;
        for(int j=0 ; j<=mxPower ; j++)
        {
            if( forY[j]==0 )
            {
                if( res[j]==1 ) ans += "R" ;
                else ans += "L" ;
            }
            else{
                if(res[j]==1) ans += "U" ;
                else ans += "D" ;
            }
        }

        if( x[i] < 0 )
        {
            for(int j=0 ; j<ans.size() ; j++)
            {
                if( ans[j]  == 'L' ) ans[j] = 'R' ;
                else if( ans[j] == 'R' ) ans[j] = 'L' ;
            }
        }

        if( y[i] < 0 )
        {
            for(int j=0 ; j<ans.size() ; j++)
            {
                if( ans[j]  == 'U' ) ans[j] = 'D' ;
                else if( ans[j] == 'D' ) ans[j] = 'U' ;
            }
        }

        if(parity==0) ans += "L" ;

        cout<<ans<<endl ;
    }

    return 0 ;
}
