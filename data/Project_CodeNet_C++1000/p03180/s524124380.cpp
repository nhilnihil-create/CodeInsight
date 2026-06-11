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
    int n; cin >> n;
    V< V<int> > a(n, V<int>(n));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];

    vll dp(1 << n);
    for (int state = 1; state < (1 << n); state++) {
        for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
            if ((state >> i & 1) && (state >> j & 1)) dp[state] += ll(a[i][j]);
        }
        for (int subset = state; subset > 0; subset = (subset - 1) & state) {
            chmax(dp[state], dp[subset] + dp[state ^ subset]);
        }
    }
    cout << dp.back() << '\n';
    return 0;
}
