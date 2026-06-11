// 見せてやるぜ、奇跡ってやつをよぉ……
#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
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
#define DEBUG_VLL(vec) REP(sz, vec.size()) cerr<<vec[sz]<<(sz==vec.size()-1?'\n':' ');

const ll MOD = 1000000007;
const ll HIGHINF = (ll)1e18;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vll a(1LL << n);
    REP(i, 1LL << n) cin >> a[i];

    V< P<ll, ll> > dp(1LL << n);
    REP(i, 1LL << n) dp[i] = make_pair(a[i], 0);

    REP(j, n) {
        REP(i, 1LL << n) {
            if (i & (1LL << j)) {
                P<ll, ll> a = dp[i], b = dp[i & ~(1LL << j)];
                if (a.first > b.first) dp[i] = make_pair(a.first, max(a.second, b.first));
                else dp[i] = make_pair(b.first, max(b.second, a.first));
            }
        }
    }

    ll ans = 0;
    rep(i, 1, 1LL << n) {
        chmax(ans, dp[i].first + dp[i].second);
        cout << ans << '\n';
    }
    return 0;
}

