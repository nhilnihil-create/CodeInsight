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
    ll a, b, c;
    cin >> a >> b >> c;
    if (a + b >= c) {
        cout << b + c << endl;
    }
    else {
        cout << b + (a+b+1) << endl;
    }
    return 0;
}
