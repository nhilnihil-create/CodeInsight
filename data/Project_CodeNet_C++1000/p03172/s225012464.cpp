#pragma region
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
typedef long long ll;
#define rep(i, a, n) for (long long i = a; i <= n; ++i)
#define per(i, a, n) for (long long i = n; i >= a; --i)
#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
/*
 *                                                     __----~~~~~~~~~~~------___
 *                                    .  .   ~~//====......          __--~ ~~
 *                    -.            \_|//     |||\\  ~~~~~~::::... /~
 *                 ___-==_       _-~o~  \/    |||  \\            _/~~-
 *         __---~~~.==~||\=_    -_--~/_-~|-   |\\   \\        _/~
 *     _-~~     .=~    |  \\-_    '-~7  /-   /  ||    \      /
 *   .~       .~       |   \\ -_    /  /-   /   ||      \   /
 *  /  ____  /         |     \\ ~-_/  /|- _/   .||       \ /
 *  |~~    ~~|--~~~~--_ \     ~==-/   | \~--===~~        .\
 *           '         ~-|      /|    |-~\~~       __--~~
 *                       |-~~-_/ |    |   ~\_   _-~            /\
 *                            /  \     \__   \/~                \__
 *                        _--~ _/ | .-~~____--~-/                  ~~==.
 *                       ((->/~   '.|||' -_|    ~~-/ ,              . _||
 *                                  -_     ~\      ~~---l__i__i__i--~~_/
 *                                  _-~-__   ~)  \--______________--~~
 *                                //.-~~~-~_--~- |-------~~~~~~~~
 *                                       //.-~~~--\
 *                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
#pragma endregion
const int maxn = 105;
const ll mod = 1e9 + 7;
ll a[maxn], b[int(1e5 + 5)], n, k;
ll dp[int(1e5 + 5)];
int main() {
    IO;
    cin >> n >> k;
    rep(i, 1, n) cin >> a[i];
    dp[0] = 1;
    rep(i, 1, n) {
        memset(b, 0, sizeof(b));
        per(j, 0, k) {
            int l = j + 1, r = min(k, j + a[i]);
            if (l <= r) {
                (b[l] += dp[j]) %= mod;
                (b[r + 1] += mod - dp[j]) %= mod;
            }
        }
        ll now = 0;
        rep(i, 0, k) {
            (now += b[i]) %= mod;
            (dp[i] += now) %= mod;
        }
    }
    cout << dp[k] << endl;
}