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
    int q , n = 0 ;
    cin >> q;
    int l[q] , r[q] , a[100005] = {0} , c[100005] = {0};
    for( int i = 0 ; i < q ; i++ ) cin >> l[i] >> r[i];
    for( int i = 2 ; i <= 100005 ; i++ ) {
        int b = 1;
        for ( int j = 2 ; j * j <= i ; j++ ) {
            if ( i % j == 0 ) b = 0;
        }
        for ( int j = 2 ; j * j <= ( i + 1 ) / 2 ; j++ ) {
            if ( ( ( i + 1 ) / 2 ) % j == 0 ) b = 0;
        }
        a[i] = b;
    }
    a[2]=0;
    for( int i = 1 ; i <= 100005 ; i++ ) {
        n += a[i];
        c[i] = n;
    }
    n = 0;
    for( int i = 0 ; i < q ; i++ ) {
        n = 0;
        n += c[r[i]] - c[l[i] - 1];
        cout << n << endl;
    }
}