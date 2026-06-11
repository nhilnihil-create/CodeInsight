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
    int n , m , x , c = 0 , d = 0;
    cin >> n >> m >> x;
	int a[m + 1] , b[n + 1] = {};
	for( int i = 1 ; i <= m ; i++ ) {
		cin >> a[i];
		b[a[i]] = 1;
	}
	for( int i = x ; i <= n ; i++ ) {
		if( b[i] == 1 ) c++;
	} 
	for( int i = x ; i >= 1 ; i-- ) {
		if( b[i] == 1 ) d++;
	}
	cout << min( c , d );
}