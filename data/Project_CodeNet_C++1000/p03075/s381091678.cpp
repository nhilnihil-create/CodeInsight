#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a , b , c , d , e , k , q , w ;
    cin >> a >> b >> c >> d >> e >> k ;
    q = max(a , b );
    w = min(a , b );
    q = max( q , c );
    q = max( q , d );
    q = max( q , e );
    w = min(w , c );
    w = min(w , d );
    w = min(w , e );
    if ( ( q - w ) <= k )
    {
        cout << "Yay!" << endl;
    }
    else
    {
        cout << ":(" << endl;
    }
    return 0;
}
