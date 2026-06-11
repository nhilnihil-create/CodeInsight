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
	int a[n + 2];
	a[0] = 0;
    a[n + 1] = 0;
    for( int i = 1 ; i <= n ; i++ ) cin >> a[i];
    int s = 0;
    for( int i = 1 ; i <= n + 1 ; i++ ){
        s += abs( a[i] - a[i - 1] );
    }
    for( int i = 1 ; i <= n ; i++ ){
        int ans = s;
        ans = ans - abs( a[i] - a[i - 1] ) - abs( a[i] - a[i + 1] ) + abs( a[i - 1] - a[i + 1] );
        cout << ans << endl;
    }
}