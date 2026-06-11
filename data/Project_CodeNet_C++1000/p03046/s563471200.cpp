#include <bits/stdc++.h>
using namespace std;

int main()
{
    int M, K;
    int bitsize;

    cin >> M >> K;
    
    bitsize = (1 << M);
    
    if ( K == 0 ) {
        for ( int i = 0; i < bitsize; i++ ) {
            cout << i << " " << i;
            if ( i < bitsize - 1 ) cout << " ";
        }
        cout << endl;
    } else if ( K >= bitsize || M == 1 ) {
        cout << -1 << endl;
    } else {
        for ( int i = 0; i < bitsize; i++ ) {
            if ( i != K ) cout << i << " ";
        }
        cout << K << " ";
        for ( int i = bitsize - 1; i >= 0; i-- ) {
            if ( i != K ) cout << i << " ";
        }
        cout << K << endl;
    }

    return ( 0 );
}
