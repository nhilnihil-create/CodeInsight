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
int main()
{
    FASTIO
    int n , m ;
    cin >> n >> m ;
    int mx = -1 , mn = BIG ;
    while ( m-- )
    {
        int l , r ;
        cin >> l >> r ;
        mx = max ( mx , l ) ;
        mn = min ( mn , r ) ;
    }
    cout << max ( mn - mx + 1 , 0 ) ;
    return 0 ;
}

