#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <set>
using namespace std;
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    ll c[5] = {};
    cin >> n;
    string a , b = "MARCH";
    for( int i = 0 ; i < n ; i++ ) {
        cin >> a;
        for( int j = 0 ; j < 5 ; j++ ) {
            if( b[j] == a[0] ) {
                c[j]++;
                break;
            }
        }
    }
    ll x = 0;
    // 選出3個 , 5 * 4 * 3
    for( int i = 0 ; i < 5 ; i++ ) {
        for( int j = i + 1 ; j < 5 ; j++ ) {
            for( int k = j + 1 ; k < 5 ; k++ ) {
                x += c[i] * c[j] * c[k];
            }
        }
    }
    cout << x;
}
