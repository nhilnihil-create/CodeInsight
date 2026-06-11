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
    int n;
    int x = 0 , y = 1;
    cin >> n;
    int a[n];
    for( int i = 0 ; i < n ; i++ ) cin >> a[i];
    sort( a , a + n );
    for( int i = 0 ; i < n ; i++ ) {
        y = 1;
        if( i == n - 1 && a[i] != y ) {
            x += y;
            break;
        } else {
            for( int j = i + 1 ; j < n ; j++ ) {
                if( a[j] == a[i] ) {
                    y++;
                    if( j == n - 1 ) {
                        if( a[i] < y ) x += y - a[i];
                        else if( a[i] > y ) x += y;
                        i = j;
                        break;
                    }
                } else {
                    if ( a[i] > y ) x += y;
                    if ( a[i] < y ) x += y - a[i];
                    i = j - 1;
                    break;
                }
            }
        }
    }
    cout << x;
}