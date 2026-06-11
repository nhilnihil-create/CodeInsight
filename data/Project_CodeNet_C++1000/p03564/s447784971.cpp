 #include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <math.h>
#include <string>
#include <set>
using namespace std;
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n , k , x = 1;
    cin >> n >> k;
    for( int i = 0 ; i < n ; i++ ) {
        if( x < k ) x *= 2;
        else x += k;
    }
    cout << x;
}

