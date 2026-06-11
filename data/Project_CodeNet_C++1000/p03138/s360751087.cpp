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

ll dp[100][2];

int main() {
    ll n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    rep(i, 100) dp[i][0] = dp[i][1] = -1;

    dp[45][0] = 0LL;
    for (ll d = 44; d >= 0; --d) {
        ll mask = 1LL<<d;
        ll num = 0;
        rep(i, n) {
            if (a[i] & mask) ++num;
        }
        //cout << num << endl;
        if (dp[d+1][1] >= 0) {
            dp[d][1] = max(dp[d][1],  dp[d+1][1] + mask * max(num, n-num));
        }
        if (dp[d+1][0] >= 0) {
            if (k & (1LL<<d)) {
                dp[d][1] = max(dp[d][1], dp[d+1][0] + mask * num);
                dp[d][0] = max(dp[d][0], dp[d+1][0] + mask * (n - num));
            }
            else {
                dp[d][0] = max(dp[d][0], dp[d+1][0] + mask * num);
            }
        }
    }
    //rep(i, 45) {
    //    cout << i << " ";
    //    for(auto p: dp[i]) {
    //        cout << p << " ";
    //    }
    //    cout << endl;
    //}
    cout << max(dp[0][0], dp[0][1]) << endl;
    return 0;
}
