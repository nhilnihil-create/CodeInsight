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
    int n , t , x , y , k;
    cin >> n;
    int a = 0 , b = 0 , c = 0;
    for( int i = 0 ; i < n ; i++ ) {
        cin >> t >> x >> y;
        k = abs( a - x ) + abs( b - y );
        if( t - c < k || ( k - t + c ) % 2 ) {
            cout << "No";
            return 0;
        }
        a = x;
        b = y;
        c = t;
    }
    cout << "Yes";
}


