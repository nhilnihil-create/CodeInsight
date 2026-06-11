#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;


/* range: ± 3.27 * 10^4 */
using i16 = short int;
/* range: 0 to 65535 */
using u16 = short unsigned int;
/* range: ± 2.14 * 10^9 */
using i32 = int;
/* range: 0 to 4.29 * 10^9 */
using u32 = unsigned int;
/* range: ± 9.22 * 10^18 */
using i64 = long long int;
/* range: 0 to 1.84 * 10^19 */
using u64 = long long unsigned int;

i32 main() {
    i32 n = 0;
    cin >> n;
    vector<double> prob_heads(n, 0.0);
    for (i32 i = 0; i < n; i++) {
        cin >> prob_heads[i];
    }

    vector<double> dp(n + 1, 0.0);
    dp[0] = 1;
    for (i32 coin = 0; coin < n; coin++) {
        for (i32 i = coin + 1; i > 0; i--) {
            dp[i] =
                dp[i - 1] * prob_heads[coin] + dp[i] * (1 - prob_heads[coin]);
        }
        dp[0] *= (1 - prob_heads[coin]);
    }

    double ans = 0.0;
    for (auto i = n / 2 + 1; i <= n; i++) {
        ans += dp[i];
    }

    cout << fixed << setprecision(10) << ans << '\n';
}