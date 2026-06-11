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
    ll n , y;
    cin >> n >> y;
    for( ll i = 0 ; i <= n ; i++ ) {
        for( ll j = 0 ;  j <= n - i ; j++ ) {
            if ( i * 10000 + j * 5000 + ( n - i - j ) * 1000 == y ) {
                cout << i << " " << j << " " << n - i - j;
                return 0;
            }
        }
    }
    cout << "-1 -1 -1";
}

