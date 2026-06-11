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
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    ll x, y;
    cin >> x >> y;
    if (x % y == 0) {
        cout << -1 << endl;
    }
    else {
        cout << x << endl;
    }
    return 0;
}
