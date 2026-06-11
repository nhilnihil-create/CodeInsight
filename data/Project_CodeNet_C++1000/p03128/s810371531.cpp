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

ll n, m;
vll can_use(10, 0);

map<ll, ll> match = { {1, 2}, {2, 5}, {3 ,5}, {4, 4}, {5, 5}, {6, 6}, {7, 3}, {8, 7}, {9, 6} };
map<ll, ll> digi;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (ll i = 0; i < m; i++) {
        ll a; cin >> a;
        can_use[a] = 1;
        if (digi.find(match[a]) == digi.end()) digi[match[a]] = a;
        else chmax(digi[match[a]], a);
    }

    vll dp(n + 1, -1);
    vll fr(n + 1, -1);
    dp[0] = 0;
    for (ll i = 1; i <= n; i++) {
        for (ll d = 9; d >= 1; d--) {
            if (can_use[d] == 0) continue;
            if (i - match[d] >= 0 && dp[i - match[d]] >= 0) {
                if (chmax(dp[i], dp[i - match[d]] + 1)) {
                    fr[i] = i - match[d];
                }
            }
        }
    }

    string ans;
    ll pre = n;
    while (pre != 0) {
        ll tmp = fr[pre];
        ans.push_back('0' + digi[pre - tmp]);
        pre = tmp;
    }
    cout << ans << '\n';
    return 0;
}
