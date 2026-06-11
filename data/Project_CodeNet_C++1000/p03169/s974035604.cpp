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

int n;
V< V< V<double> > > dp;

double dfs(int c1, int c2, int c3) {
    if (dp[c1][c2][c3] >= 0) return dp[c1][c2][c3];
    if (c1 == 0 && c2 == 0 && c3 == 0) return dp[c1][c2][c3] = 0;
    double tmp = double(n - c1 - c2 - c3) / double(n);
    if (c1 > 0) tmp += double(c1) * (1 + dfs(c1 - 1, c2, c3)) / double(n);
    if (c2 > 0) tmp += double(c2) * (1 + dfs(c1 + 1, c2 - 1, c3)) / double(n);
    if (c3 > 0) tmp += double(c3) * (1 + dfs(c1, c2 + 1, c3 - 1)) / double(n);
    return dp[c1][c2][c3] = double(n) * tmp / double(c1 + c2 + c3);
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cin >> n;
    V<int> a(n);
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) cnt1++;
        else if (a[i] == 2) cnt2++;
        else cnt3++;
    }

    dp.resize(n + 1, V< V<double> >(n + 1, V<double>(n + 1, -1)));
    cout << dfs(cnt1, cnt2, cnt3) << '\n';
    return 0;
}
