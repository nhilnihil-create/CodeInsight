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
    int q;
    cin >> q;
    int l[q] , r[q] , p[100005] = {0} , a[100005] = {0} , b[100005] = {0};
    for (int i = 0 ; i < q ; i++) cin >> l[i] >> r[i];
    for (int i = 2 ; i <= 100000 ; i++) {
        p[i] = 1;
        for ( int j = 2 ; j * j <= i ; j++ ) if ( i % j == 0 ) p[i] = 0;
    }
    for( int i = 1 ; i <= 100000 ; i++ ) if( p[i] && p[(i + 1) / 2] ) a[i] = 1;
    for( int i = 1 ; i <= 100000 ; i++ ) b[i] = b[i - 1] + a[i];
    for( int i = 0 ; i < q ; i++ ) cout << b[r[i]] - b[l[i] - 1] << endl;
}
