#include<bits/stdc++.h>

#define ll   	long long
#define pb	    push_back
#define F   	first
#define S	    second
#define B   	begin()
#define E	    end()
#define FASTIO   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


using namespace std ;



int main()
{
    FASTIO
    int r , d , x ;
    cin >> r >> d >> x ;
    for ( int i = 0 ; i < 10 ; i++ )
    {
        x = r*x - d ;
        cout << x << "\n" ;
    }
    return 0 ;
}

