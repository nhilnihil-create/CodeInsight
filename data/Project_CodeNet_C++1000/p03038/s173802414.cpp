#include<bits/stdc++.h>

#define ll   	long long
#define pb	    push_back
#define F   	first
#define S	    second
#define B   	begin()
#define E	    end()
#define FASTIO   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


using namespace std ;


const int BIG = 1e5 + 7 ;
int l[BIG] , r[BIG] ;
pair < int , int > p[BIG] ;
int rep[BIG];
bool cmp ( pair < int , int > x , pair < int , int > y )
{
    return x.S > y.S ;
}
int main()
{
    FASTIO
    int n , m ;
    cin >> n >> m ;
    vector < int > a ;
    for ( int i = 0 ; i < n ; i++ )
    {
        int x ;
        cin >> x ;
        a.pb(x);
    }

    for ( int i = 0 ; i < m ; i++ )
        cin >> p[i].F >> p[i].S ;

    sort ( p , p + m , cmp ) ;
    sort ( a.B , a.E ) ;
    int start = 0 , sum = 0 ;
    for ( int i = 0 ; i < m ; i++ )
    {
        if ( sum > n ) break ;
        int cnt = 0 ;
        for ( int j = start ; j < n ; j++ )
        {
            if ( a[j] >= p[i].S || cnt == p[i].F ) break ;
            a[j] = p[i].S ;
            start = j + 1 ;
            cnt++;
            sum++;
        }
    }
    ll ans = 0 ;
    for ( int i = 0 ; i < n ; i++ ) ans += a[i] ;
    cout << ans ;
    return 0 ;
}

