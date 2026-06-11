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
#include <queue>
#include <utility>
using namespace std;
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for( int i = 0 ; i < n ; i++ ) cin >> a[i];
    sort( a , a + n );
    cout << abs( a[n - 1] - a[0] );
}
