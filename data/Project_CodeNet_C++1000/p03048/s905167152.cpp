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
    int r, g, b, n;
    cin >> r >> g >> b >> n;
    int ans = 0;
    rep(i, 3001) rep(j, 3001) {
        if (n - i * r - j * g < 0) continue;
        if ((n - i * r - j * g) % b == 0) ++ans;
    }
    cout << ans << endl;
    return 0;
}