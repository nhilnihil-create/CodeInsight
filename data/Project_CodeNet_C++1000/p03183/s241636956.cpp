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
    V< P<int, P<int, int> > > wsv(n);
    for (int i = 0; i < n; i++) cin >> wsv[i].first >> wsv[i].second.first >> wsv[i].second.second;
    sort(ALL(wsv), [&](P<int, P<int, int> > i, P<int, P<int, int> > j) {
        return i.first + i.second.first < j.first + j.second.first;
    });

    vvll dp(2, vll(10002, -1));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        dp[1] = vll(10002, -1);
        for (int j = 0; j < 10002; j++) {
            if (dp[0][j] == -1) continue;
            chmax(dp[1][j], dp[0][j]);
            if (j != 10001 && j <= wsv[i].second.first) chmax(dp[1][min(10001, j + wsv[i].first)], dp[0][j] + wsv[i].second.second);
        }
        swap(dp[0], dp[1]);
    }
    cout << *max_element(ALL(dp[0])) << '\n';
    return 0;
}
