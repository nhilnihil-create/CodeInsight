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
V<int> a, b;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    a.resize(n), b.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    ll ans = 0;
    for (int i = 0; i < 29; i++) {
        // i bit 目を見る時は i bit 以下だけでいいのでマスク
        int mask = (1 << (i + 1)) - 1;
        V<int> rema(n), remb(n);
        for (int i = 0; i < n; i++) rema[i] = a[i] & mask;
        for (int i = 0; i < n; i++) remb[i] = b[i] & mask;
        sort(ALL(remb));
        ll bcnt = 0;
        // a + b の取りうる値は 2 * (2^(i+1) - 1) = 4 * 2^i - 2 < 4 * 2^i
        // 2^i bit 目が立つのは [2^i, 2*2^i-1], [3*2^i, 4*2^i-1]
        for (int j = 0; j < n; j++) {
            bcnt += lower_bound(ALL(remb), (1 << (i + 1)) - rema[j]) - lower_bound(ALL(remb), (1 << i) - rema[j]);
            bcnt += lower_bound(ALL(remb), (1 << (i + 2)) - rema[j]) - lower_bound(ALL(remb), ((1 << i) + (1 << (i + 1))) - rema[j]);
        }
        if (bcnt & 1) ans += 1 << i;
    }
    cout << ans << '\n';
    return 0;
}
