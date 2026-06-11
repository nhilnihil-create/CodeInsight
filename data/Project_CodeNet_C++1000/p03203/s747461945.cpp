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
    ll h, w, n; cin >> h >> w >> n;
    vvll obstacle(h);
    REP(i, n) {
        ll x, y; cin >> x >> y;
        obstacle[x - 1].emplace_back(y - 1);
    }
    ll tmp = 0, left = 0, right = 1;
    while (true) {
        if (tmp + 1 >= h) break;
        sort(ALL(obstacle[tmp + 1]));
        if (obstacle[tmp + 1].empty()) {
            tmp++, right++;
        } else {
            if (obstacle[tmp + 1][0] < right) break;
            else {
                right = min(right + 1, obstacle[tmp + 1][0]);
                tmp++;
            }
        }
    }

    cout << tmp + 1 << '\n';
    return 0;
}
