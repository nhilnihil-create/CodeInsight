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
    int n; cin >> n;
    vll a(n), b(n);
    for (int i=0; i<n; i++) cin >> a[i] >> b[i];
    vll ord(n); iota(ALL(ord), 0LL);
    sort(ALL(ord), [&](ll i, ll j) {
        if (b[i]-a[i]>=0 || b[j]-a[j]>=0) return b[i]-a[i] > b[j]-a[j];
        else return b[i] > b[j];
    });
    if (b[ord[0]] - a[ord[0]] == 0) cout << 0 << '\n';
    else {
        ll ans = 0, tmp = 0;
        for (int i=0; i<n; i++) {
            if (b[ord[i]] - a[ord[i]] > 0) {
                ans += a[ord[i]];
            } else if (b[ord[i]] - a[ord[i]] == 0) {
                ans += a[ord[i]];
            } else if (b[ord[i]] - a[ord[i]] < 0) {
                if (i == n-1) {
                    ans += a[ord[i]] - b[ord[i]];
                } else {
                    ans += a[ord[i]];
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
