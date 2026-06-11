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
#define ALL(v) v.begin(),v.end()
template < class T > inline bool chmax(T& a, T b) {if (a < b) { a=b; return true; } return false; }
template < class T > inline bool chmin(T& a, T b) {if (a > b) { a=b; return true; } return false; }
#define DEBUG_VLL(vec) for(int sz=0;sz<int(vec.size());sz++) std::cerr<<vec[sz]<<(sz==vec.size()-1?'\n':' ');

const long long MOD = 1000000007;
const long long HIGHINF = (long long)1e18;
const int INF = (int)1e9;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    V< V<int> > a(n, V<int>(n));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
    vll cost(1 << n, 0);
    for (int i = 0; i < (1 << n); i++) {
        for (int r1 = 0; r1 < n; r1++) {
            for (int r2 = r1 + 1; r2 < n; r2++) {
                if ((i >> r1 & 1) && (i >> r2 & 1)) cost[i] += a[r1][r2];
            }
        }
    }

    vll dp(1 << n, 0);
    for (int state = 0; state < (1 << n); state++) {
        dp[state] = cost[state];
        for (int subs = state; subs > 0; subs = (subs - 1) & state) {
            chmax(dp[state], dp[subs] + dp[state ^ subs]);
        }
    }
    cout << dp.back() << '\n';
    return 0;
}
