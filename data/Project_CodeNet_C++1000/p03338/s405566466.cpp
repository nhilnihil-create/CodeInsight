#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <math.h>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n , ans = 0;
    string s;
    cin >> n >> s;
	for( int i = 1 ; i < n ; i++ ) {
    	int a[26] = {}, b[26] = {} , e = 0;
    	for ( int j = 0 ; j < i ; j++ ) a[s[j] - 'a'] = 1;
        for ( int j = i ; j < n ; j++ ) b[s[j] - 'a'] = 1;
        for ( int j = 0 ; j < 26 ; j++ ) if ( a[j] && b[j] ) e++;
        ans = max( ans , e );
	}
	cout << ans;
}  
