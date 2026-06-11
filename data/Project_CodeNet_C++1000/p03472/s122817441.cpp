#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <math.h>
#include <string>
using namespace std;
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n , h , c = 0 , d = 0;
    cin >> n >> h;
    int a[n] , b[n];
    for( int i = 0 ; i < n ; i++ ) {
        cin >> a[i] >> b[i];
        d = max( d , a[i] );
    }
    sort( b , b + n );
    for ( int i = n - 1 ; i >= 0 ; i-- ) {
        if ( b[i] < d ) break;
        h -= b[i];
        c++;
        if ( h <= 0 ) {
            cout << c;
            return 0;
        }
    }
    cout << c + (h - 1) / d + 1;
}
