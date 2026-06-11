#include <bits/stdc++.h>

#define PI (acos(-1.0))
#define DBG printf("Hi\n")
#define loop(i,n) for(i =1 ; i<=n; i++)
#define mp make_pair
#define pb push_back
#define mod 1000000007LL
#define INF 1000000000
#define xx first
#define yy second
#define sq(x) ((x)*(x))
#define eps 0.0000000001
#define i64 long long int
#define ui64 unsigned long long int

using namespace std ;

#define maxn 100005

vector < pair< pair<int,int> ,int > > vp ;

int main()
{
    int i , j , k , l , m , n ;

    scanf("%d",&l) ;

    for(i=1 ; i<=20 ; i++)
    {
        if(  (1<<i) - 1 >= l ) break ;
    }

    n = i ;

    for(i=1 ; i<n ; i++)
    {
        vp.pb( mp( mp(i,i+1) , 0 ) ) ;
        vp.pb( mp( mp(i,i+1) , (1<<(i-1)) ) ) ;
    }

    l -= ( (1<<(n-1))  ) ;

    int offset = (1<<(n-1)) ;

    for(i=n-1 ; i>=1 ; i--)
    {
        j = i-1 ;
        if( (1<<j) <= l )
        {
            vp.pb( mp(  mp(i,n) , offset ) ) ;
            l -= (1<<j) ;
            offset += (1<<j) ;
        }
    }

    printf("%d %d\n", n , (int)vp.size() ) ;

    for(i=0 ; i<(int)vp.size() ; i++) printf("%d %d %d\n", vp[i].xx.xx,vp[i].xx.yy, vp[i].yy ) ;

    return 0 ;
}
