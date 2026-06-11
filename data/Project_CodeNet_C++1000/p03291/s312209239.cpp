#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <bitset>
#include <set>
#include <unordered_set>
#include <cmath>
#include <complex>
#include <deque>
#include <iterator>
#include <numeric>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <limits>
#include <iomanip>
#include <functional>
#include <cassert>
using namespace std;

using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
#define REP(i, n) rep(i, 0, n)
#define ALL(v) v.begin(),v.end()
template < class T > inline bool chmax(T& a, T b) {if (a < b) { a=b; return true; } return false; }
template < class T > inline bool chmin(T& a, T b) {if (a > b) { a=b; return true; } return false; }
#define DEBUG_VLL(vec) REP(sz, vec.size()) std::cerr<<vec[sz]<<(sz==vec.size()-1?'\n':' ');

const long long MOD = 1000000007;
const long long HIGHINF = (long long)1e18;
const int INF = (int)1e9;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s; cin >> s;
    vvll dp(4, vll(s.size() + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') {
            dp[1][i + 1] = (dp[0][i] + dp[1][i]) % MOD;
            dp[0][i + 1] = dp[0][i];
            dp[2][i + 1] = dp[2][i];
            dp[3][i + 1] = dp[3][i];
        } else if (s[i] == 'B') {
            dp[2][i + 1] = (dp[1][i] + dp[2][i]) % MOD;
            dp[0][i + 1] = dp[0][i];
            dp[1][i + 1] = dp[1][i];
            dp[3][i + 1] = dp[3][i];
        } else if (s[i] == 'C') {
            dp[3][i + 1] = (dp[2][i] + dp[3][i]) % MOD;
            dp[0][i + 1] = dp[0][i];
            dp[1][i + 1] = dp[1][i];
            dp[2][i + 1] = dp[2][i];
        } else {
            // A
            dp[1][i + 1] += (dp[0][i] + dp[1][i]) % MOD;
            dp[0][i + 1] += dp[0][i];
            dp[2][i + 1] += dp[2][i];
            dp[3][i + 1] += dp[3][i];
            // B
            dp[2][i + 1] += (dp[1][i] + dp[2][i]) % MOD;
            dp[0][i + 1] += dp[0][i];
            dp[1][i + 1] += dp[1][i];
            dp[3][i + 1] += dp[3][i];
            // C
            dp[3][i + 1] += (dp[2][i] + dp[3][i]) % MOD;
            dp[0][i + 1] += dp[0][i];
            dp[1][i + 1] += dp[1][i];
            dp[2][i + 1] += dp[2][i];
            
            dp[0][i + 1] %= MOD;
            dp[1][i + 1] %= MOD;
            dp[2][i + 1] %= MOD;
            dp[3][i + 1] %= MOD;
        }
    }
    cout << dp[3][s.size()] << '\n';
    return 0;
}
