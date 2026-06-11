#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define ins insert
#define mp make_pair
#define pii pair<int, int>
#define pil pair<int, ll>
#define pib pair<int, bool>
#define SET(a, c) memset(a, c, sizeof(a))
#define MOD 1000000007
#define enld endl
#define endl "\n"
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define FOUND(u, val) u.find(val) != u.end()
#define max_self(a, b) a = max(a, b);

#include <string>
#include <vector>
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
//#include <algorithm>
//#include <set>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int base = 1;
    while (base <= n) base *= 2;
    vl tree(2 * base);

    ll heights[n], ar[n];
    for (ll &x : heights) cin >> x;
    for (ll &x : ar) cin >> x;

    /* 
9
4 2 5 8 3 6 1 7 9
6 8 8 4 6 3 5 7 5
 */
    /* 
4
3 1 4 2
10 20 30 40
 */

    vl dp(n + 1, 0);
    ll ans = 0;
    for (int flower = 0; flower < n; flower++) {
        int x = heights[flower] + base;
        ll best = 0;
        while (x > 1) {
            if (x % 2 == 1) {
                max_self(best, tree[x - 1]);
            }
            x /= 2;
        }

        dp[heights[flower]] = best + ar[flower];

        for (int i = base + heights[flower]; i >= 1; i /= 2) {
            max_self(tree[i], dp[heights[flower]]);
        }
    }

    // Below is O(n ^2) solution
    /* vl dp(n + 1, 0);
    // dp[i] - the max total beauty so far if the last taken flower has height i.
    ll ans = 0;
    // GO through every flower
    for (int flower = 0; flower < n; flower++) {
        // Go through all flowers shorter in length
        for (int i = 0; i < heights[flower]; ++i) {
            // If the sum for a shorter flower (dp[i]) + current flower value
            //  is greater than sum for current flower, update it.
            if (dp[i] + ar[flower] > dp[heights[flower]])
                dp[heights[flower]] = dp[i] + ar[flower];
        }
    } */
    for (int i = 0; i <= n; i++) max_self(ans, dp[i]);
    cout << ans;
}