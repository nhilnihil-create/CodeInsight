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
    int n;
    cin >> n;
    int a[3][n + 1];
    for ( int i = 0 ; i <= 2 ; i++ ) {
        for ( int j = 0 ; j <= n ; j++ ) a[i][j] = 0;
    }
    for ( int i = 1 ; i <= 2 ; i++ ) {
        for ( int j = 1 ; j <= n ; j++ ) {
            int x;
            cin >> x;
            a[i][j] = max( a[i - 1][j] , a[i][j - 1] ) + x;
        }
    }
    cout << a[2][n];
}

