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
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    vector<vector<ll>> dp(45, vector<ll>(2, -1));
    dp[44][0] = 0;
    for (int i = 43; i >= 0; --i) {
        ll cnt = 0;
        rep(j, n) {
            //cout << (1LL<<i) << endl;
            if (a[j] & (1LL<<i)) {
                //cout << a[j] << endl;
                ++cnt;
            }
        }
        //cout << i << " " << cnt << endl;
        if (dp[i+1][0] >= 0) {
            if (k & (1LL<<i)) {
                dp[i][0] = max(dp[i][0], dp[i+1][0] + (n - cnt) * (1LL<<i));
                dp[i][1] = max(dp[i][1], dp[i+1][0] + cnt * (1LL<<i));
            }
            else {
                dp[i][0] = max(dp[i][0], dp[i+1][0] + cnt * (1LL<<i));
            }
        }
        if (dp[i+1][1] >= 0) {
            dp[i][1] = max(dp[i][1], dp[i+1][1] + max(cnt, n-cnt) * (1LL<<i));
        }
    }
    //for (int i = 44; i >= 0; --i) {
    //    cout << dp[i][0] << " " << dp[i][1] << endl;
    //}
    cout << max(dp[0][0], dp[0][1]) << endl;
    return 0;
}
