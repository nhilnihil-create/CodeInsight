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
    int n;
    cin >> n;
    vector <ll> a(n) , b(n);
    for ( int i = 0 ; i < n ; i++ ) {
		cin >> a[i];
		b[i] = a[i]; 
	} 
    sort( b.begin() , b.end() );
    int x = ( n - 2 ) / 2;
    for ( int i = 0 ; i < n ; i++ ) {
        if ( a[i] <= b[x] ) cout << b[x + 1] << endl;
        else cout << b[x] << endl;
    } 
}
