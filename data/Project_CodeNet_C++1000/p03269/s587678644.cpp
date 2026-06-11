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

const ll MOD = 1000000007;
const ll HIGHINF = (ll)1e18;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll l; cin >> l;
    V<P<P<ll, ll>, ll> > edges;
    ll r = 0;
    while (r<=19 && (1LL<<r) <= l) r++;

    REP(i, r-1) {
        edges.push_back({{i, i+1}, 1LL<<i});
        edges.push_back({{i, i+1}, 0});
    }

    for (ll i=r-2; i>=0; i--) {
        if (l-(1LL<<i) >= (1LL<<(r-1))) {
            edges.push_back({{i, r-1}, l-(1LL<<i)});
            l -= (1LL<<i);
        }
    }

    cout << r << ' ' << edges.size() << '\n';
    REP(i, edges.size()) {
        cout << edges[i].first.first+1 << ' ' << edges[i].first.second+1 << ' ' << edges[i].second << '\n';
    }
    return 0;
}
