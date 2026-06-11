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
    ll n, q; cin >> n;
    string s; cin >> s;
    cin >> q;
    vll k(q);
    for (ll i = 0; i < q; i++) cin >> k[i];

    for (ll _q = 0; _q < q; _q++) {
        ll tmpk = k[_q];
        ll cntd = 0, cntm = 0, cntdm = 0;
        ll ans = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == 'D') cntd++;
            else if (s[j] == 'M') {
                cntdm += cntd;
                cntm++;
            } else if (s[j] == 'C') ans += cntdm;

            if (j - tmpk + 1 >= 0) {
                if (s[j - tmpk + 1] == 'M') cntm--;
                else if (s[j - tmpk + 1] == 'D') cntd--, cntdm -= cntm;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
