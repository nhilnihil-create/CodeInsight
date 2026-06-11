#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
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
    i32 n, k;
    cin >> n >> k;

    vector<i32> stones(n);
    for (i32 i = 0; i < n; i++) {
        cin >> stones[i];
    }

    vector<bool> dp(k + 1, false);

    for (i32 i = 1; i <= k; i++) {
        for (auto stone : stones) {
            if (dp[i]) {
                break;
            } else if (i >= stone) {
                dp[i] = !dp[i - stone];
            }
        }
    }

    if (dp[k]) {
        cout << "First" << '\n';
    } else {
        cout << "Second" << '\n';
    }
}