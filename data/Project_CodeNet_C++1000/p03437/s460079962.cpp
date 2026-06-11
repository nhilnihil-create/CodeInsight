#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <iomanip>
#include <algorithm>
#include <stack>
using namespace std;

#define INF 1e18
#define int long long



signed main() {
    int x, y; cin >> x >> y;

    if(x % y == 0) {
        cout << -1 << endl;
        return 0;
    }

    cout << x << endl;
    return 0;
}
