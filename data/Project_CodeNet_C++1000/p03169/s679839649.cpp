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
const int maxn = 305;
int a[4], n;
double dp[maxn][maxn][maxn];
double dfs(int c1, int c2, int c3) {
    if (!c1 && !c2 && !c3) return 0;
    if (dp[c1][c2][c3] > 0) return dp[c1][c2][c3];
    double sum = c1 + c2 + c3;
    double ans = n / sum;
    if (c1) ans += c1 / sum * dfs(c1 - 1, c2, c3);
    if (c2) ans += c2 / sum * dfs(c1 + 1, c2 - 1, c3);
    if (c3) ans += c3 / sum * dfs(c1, c2 + 1, c3 - 1);
    return dp[c1][c2][c3] = ans;
}
int main() {
    IO;
    cin >> n;
    rep(i, 1, n) {
        int x;
        cin >> x;
        a[x]++;
    }
    cout << fixed << setprecision(10) << dfs(a[1], a[2], a[3]) << endl;
}