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
    int n , x , c = 1001 , m;
    cin >> n >> x;
    for( int i = 0 ; i < n ; i++ ) {
        cin >> m;
        c = min( c , m );
        x -= m;
    }
    cout << n + x / c;
}
