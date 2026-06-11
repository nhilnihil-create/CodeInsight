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
    int n , k , c = 0;
    cin >> n >> k;
    int a[n];
    for( int i = 0 ; i < n ; i++ ) cin >> a[i];
    sort( a , a + n );
    for( int i = 0 ; i < n ; i++ ) if ( a[i] != a[i + 1] ) c++;
    int b[c] , x = 0;
    for( int i = 0 ; i < c ; i++ ) b[i] = 0;
    for( int i = 0 ; i < n ; i++ ) {
        b[x]++;
        if ( a[i] != a[i + 1] ) x++;
    }
    if( c <= k ) {
        cout << 0;
    } else {
        sort( b , b + c );
        int ans = 0;
        for( int i = 0 ; i < c - k ; i++ ) ans += b[i];
        cout << ans;
    }
}
