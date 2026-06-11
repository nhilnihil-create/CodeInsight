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
    int a , x = 0 , y = 0;
    cin >> a;
    int b[a];
    for( int i = 0 ; i < a ; i++ ) cin >> b[i];
    sort( b , b  + a );
    for( int i = 0 ; i < a ; i++ ) {
        if( i % 2 ) y += b[i];
        else x += b[i];
    }
    cout << abs( x - y );
}