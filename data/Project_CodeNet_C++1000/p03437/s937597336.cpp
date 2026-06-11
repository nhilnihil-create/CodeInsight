#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    ll x, y;
    cin >> x >> y;
    if (y == 1 || x % y == 0) {
        cout << -1 << endl;
        return 0;
    }
    cout << x * (y - 1LL) << endl;
    return 0;
}
