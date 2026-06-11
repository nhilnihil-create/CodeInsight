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
    ll n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<vector<ll>> dp(50, vector<ll>(2, -1));
    dp[49][0] = 0;
    //cout << "test" << endl;
    for (ll i = 48; i >= 0; --i) {
        ll cnt1 = 0;
        //cout << i << endl;
        rep(j, n) {
            if (a[j]&(1LL<<i)) {
                ++cnt1;
            }
        }
        if (dp[i+1][0] >= 0) {
            if ((k&(1LL<<i))) {
                dp[i][0] = max(dp[i][0], dp[i+1][0] + (n-cnt1) * (1LL<<i));
                dp[i][1] = max(dp[i][1], dp[i+1][0] + cnt1 * (1LL<<i));
            }
            else {
                dp[i][0] = max(dp[i][0], dp[i+1][0] + cnt1 * (1LL<<i));
            }
        }
        if (dp[i+1][1] >= 0) {
            dp[i][1] = max(dp[i][1], dp[i+1][1] + max(n-cnt1, cnt1) * (1LL<<i));
        }
    }
    //rep(i, 50) {
    //    cout << dp[i][0] << " " << dp[i][1] << endl;
    //}
    cout << max(dp[0][0], dp[0][1]) << endl;
    return 0;
}
