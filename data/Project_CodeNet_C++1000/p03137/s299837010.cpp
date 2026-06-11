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
    int n, m;
    cin >> n >> m;
    vector<int> x(m);
    rep(i, m) cin >> x[i];
    if (m == 1 || n >= m) {
        cout << 0 << endl;
        return 0;
    }
    sort(x.begin(), x.end());
    vector<int> diff(m-1);
    rep(i, m-1) {
        diff[i] = x[i+1] - x[i];
    }
    sort(diff.rbegin(), diff.rend());
    int ans = 0;
    rep(i, m-1) {
        ans += diff[i];
    }
    rep(i, n-1) {
        ans -= diff[i];
    }
    cout << ans << endl;
    return 0;
}
