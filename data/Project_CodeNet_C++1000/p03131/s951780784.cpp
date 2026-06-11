#include <iostream>
#include <vector> 
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <iomanip>
#include <list>
#include <deque>
using namespace std;

#define int long long

int n, a[3][3], b[10];
bool appear[3][3];

signed main() { 
    int k,a, b;
    cin >> k >> a >> b;

    if(a + 2 >= b) {
        cout << 1 + k << endl;
        return 0;
    }

    int rep = max(0.0, floor((k - (a - 1)) / 2));
    int res = 1 + k - 2 * rep; 
    int ans = (b - a) * rep + res;
 
    cout << ans << endl;
    return 0;
}
