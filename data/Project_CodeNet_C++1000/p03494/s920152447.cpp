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
    cin.tie();
    int n , m = 0 , x = 0;
    cin >> n;
    ll a[n];
    for( int i = 0 ; i < n ; i++ ) cin >> a[i];
    while( m == 0 ) {
        for( int i = 0 ; i < n ; i++ ) {
            if( a[i] % 2 ) m = 1;
        }
        if( m == 0 ) {
            for( int i = 0 ; i < n ; i++ ) {
                a[i] /= 2;
            }
        }
        x++;
    }
    cout << x - 1;
}