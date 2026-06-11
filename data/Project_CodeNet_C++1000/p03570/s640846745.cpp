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
    string s; cin >> s;
    int n = s.size();
    V<int> a(n + 1, 0);
    REP(i, n) a[i + 1] = a[i] ^ (1 << (s[i] - 'a'));

    V<int> dp(n + 1, 200005);
    dp[0] = 0;
    V<int> mdp(1 << 26, 200005);
    mdp[0] = 0;
    for (int i = 0; i < n; i++) {
        dp[i + 1] = mdp[a[i + 1]] + 1;
        for (int j = 0; j < 26; j++) {
            chmin(dp[i + 1], mdp[a[i + 1] ^ (1LL << j)] + 1);
        }
        chmin(mdp[a[i + 1]], dp[i + 1]);
    }
    cout << dp[n] << '\n';
    return 0;
}
