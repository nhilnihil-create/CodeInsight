#include<bits/stdc++.h>
#define ll      long long
#define pb	    push_back
#define F	    first
#define S	    second
#define B	    begin()
#define E	    end()
#define pii     pair < ll , ll >
#define FASTIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std ;
int jamil ;
int main()
{
    FASTIO
    int h , w ;
    cin >> h >> w ;
    int c[11][11];
    for ( int i = 0 ; i < 10 ; i++ )
        for ( int j = 0 ; j < 10 ; j++ )
             cin >> c[i][j] ;
    for ( int k = 0 ; k < 10 ; k++ )
        for ( int i = 0 ; i < 10 ; i++ )
            for ( int j = 0 ; j < 10 ; j++ )
            if ( c[i][j] > c[i][k] + c[k][j] )
                c[i][j] = c[i][k] + c[k][j] ;
    int ans = 0 ;
    for ( int i = 0 ; i < h ; i++ )
        for ( int j = 0 ; j < w ; j++ )
        {
            int x ;
            cin >> x ;
            if( x >= 0 )
                ans+=c[x][1];
        }
    cout << ans ;
	return 0 ;
}
