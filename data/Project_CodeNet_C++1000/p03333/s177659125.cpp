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
    vll l(n), r(n);
    REP(i, n) cin >> l[i] >> r[i];

    set< P<ll, P<ll, ll> > > sl, sr;
    REP(i, n) sl.insert(make_pair(l[i], make_pair(-r[i], i))), sr.insert(make_pair(r[i], make_pair(-l[i], i)));
    
    ll tmp1 = 0, pos = 0;
    REP(i, n) {
        if (i % 2 == 0) {  // to right
            P<ll, P<ll, ll> > tmp = *(--sl.end());
            sl.erase(--sl.end());
            sr.erase(make_pair(-tmp.second.first, make_pair(-tmp.first, tmp.second.second)));
            if (pos < tmp.first) {
                tmp1 += tmp.first - pos;
                pos = tmp.first;
            }
        } else { // to left
            P<ll, P<ll, ll> > tmp = *(sr.begin());
            sr.erase(sr.begin());
            sl.erase(make_pair(-tmp.second.first, make_pair(-tmp.first, tmp.second.second)));
            if (pos > tmp.first) {
                tmp1 += pos - tmp.first;
                pos = tmp.first;
            }
        }
    }
    ll ans = tmp1 + abs(pos);
    
    sl.clear(), sr.clear();
    REP(i, n) sl.insert(make_pair(l[i], make_pair(-r[i], i))), sr.insert(make_pair(r[i], make_pair(-l[i], i)));
    ll tmp2 = 0;
    pos = 0;
    REP(i, n) {
        if (i % 2 == 1) {  // to right
            P<ll, P<ll, ll> > tmp = *(--sl.end());
            sl.erase(--sl.end());
            sr.erase(make_pair(-tmp.second.first, make_pair(-tmp.first, tmp.second.second)));
            if (pos < tmp.first) {
                tmp2 += tmp.first - pos;
                pos = tmp.first;
            }
        } else { // to left
            P<ll, P<ll, ll> > tmp = *(sr.begin());
            sr.erase(sr.begin());
            sl.erase(make_pair(-tmp.second.first, make_pair(-tmp.first, tmp.second.second)));
            if (pos > tmp.first) {
                tmp2 += pos - tmp.first;
                pos = tmp.first;
            }
        }
    }
    
    cout << max(ans, tmp2 + abs(pos)) << '\n';
    return 0;
}
