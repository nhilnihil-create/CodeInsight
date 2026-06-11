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
template<class T> inline bool chmax(T& a, T b) {if (a<b) {a=b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) {if (a>b) {a=b; return true;} return false;}
#define DEBUG_VLL(vec) REP(i, vec.size()) cerr<<vec[i]<<(i==vec.size()-1?'\n':' ');

const ll MOD = 1000000007;
const ll HIGHINF = (ll)1e18;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vll a(n); REP(i, n) cin >> a[i];
    vll acca(n+1, 0);
    REP(i, n) acca[i+1] = acca[i] + a[i];
    ll li = 1, ri=3;
    ll diff = HIGHINF;
    for (; ri<n; ri++) {
        if (abs((acca[ri]-acca[2])-(acca[n]-acca[ri])) < diff) {
            diff = abs((acca[ri]-acca[2])-(acca[n]-acca[ri]));
        } else break;
    }
    ri--;
    ll ans = max({a[0], a[1], acca[n]-acca[ri], acca[ri]-acca[2]}) - min({a[0], a[1], acca[n]-acca[ri], acca[ri]-acca[2]});
    for (int i=2; i<n-1; i++) {
        ll ldif = abs((acca[i]-acca[li]) - (acca[li]-acca[0]));
        for (ll ltmp=li+1; ltmp<i; ltmp++) {
            if (ldif > abs((acca[i]-acca[ltmp]) - (acca[ltmp]-acca[0]))) {
                ldif = abs((acca[i]-acca[ltmp]) - (acca[ltmp]-acca[0]));
                li = ltmp;
            } else break;
        }

        if (ri <= i) ri = i+1;
        ll rdif = abs((acca[n]-acca[ri]) - (acca[ri]-acca[i]));
        for (ll rtmp=ri+1; rtmp<n; rtmp++) {
            if (rdif > abs((acca[n]-acca[rtmp]) - (acca[rtmp]-acca[i]))) {
                rdif = abs((acca[n]-acca[rtmp]) - (acca[rtmp]-acca[i]));
                ri = rtmp;
            } else break;
        }
        chmin(ans, max({acca[li]-acca[0], acca[i]-acca[li], acca[n]-acca[ri], acca[ri]-acca[i]}) - min({acca[li]-acca[0], acca[i]-acca[li], acca[n]-acca[ri], acca[ri]-acca[i]}));
    }
    cout << ans << '\n';
    return 0;
}
