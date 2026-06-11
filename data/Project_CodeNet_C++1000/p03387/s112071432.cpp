#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <math.h>
#include <string>
#include <queue>
#include <utility>
using namespace std;
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n[3] , a , b , c;
    for( int i = 0 ; i < 3 ; i++) {
        cin >> n[i];
    }
    a = n[0];
    b = n[1];
    c = n[2];
    n[0] = min( min( a , b ) , c );
    n[2] = max( max( a , b ) , c );
    n[1] = a + b + c - n[0] - n[2];
    int x = n[2] - n[1] + ( n[1] - n[0] ) / 2;
    if( ( n[1] - n[0] ) % 2 == 0 ) {
        cout << x;
    } else{
        cout << x + 2;
    }
}