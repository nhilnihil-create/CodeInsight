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

vvll dp;
vll acc;
ll dfs(int l, int r) {
    if (dp[l][r] != HIGHINF) return dp[l][r];
    if (l + 1 == r) return dp[l][r] = acc[r] - acc[l];
    ll ret = HIGHINF;
    for (int i = l + 1; i < r; i++) chmin(ret, dfs(l, i) + dfs(i, r) + acc[r] - acc[l]);
    return dp[l][r] = ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    acc.resize(n + 1, 0);
    for (int i = 0; i < n; i++) {
        ll a; cin >> a;
        acc[i + 1] = acc[i] + a;
    }
    dp.resize(n + 1, vll(n + 1, HIGHINF));
    cout << dfs(0, n) - acc.back() << '\n';
    return 0;
}
