//
//  main.cpp
//

#include <algorithm>
#include <array>
#include <assert.h>
#include <complex>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <math.h>
#include <memory>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = int64_t;
using ull = uint64_t;
constexpr ll LL_MAX = numeric_limits<ll>::max();
constexpr ull ULL_MAX = numeric_limits<ull>::max();

template<typename T>
vector<T> make_vec_nd(T init, ll size) {
	return vector<T>(size, init);
}
template<typename T, typename... Args>
auto make_vec_nd(T init, ll size, Args... rest) {
	auto inner = make_vec_nd(init, rest...);
	return vector<decltype(inner)>(size, inner);
}

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define rrep(i, a, b) for (ll i = (a)-1; i >= (b); i--)

int main() {
    ll H, W, N;
    cin >> W >> H >> N;
    struct P {
        ll x;
        ll y;
    };
    vector<P> pts(N);
    rep(i,0,N) {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        pts[i] = {x, y};
    }
    vector<set<ll>> pts_y(H);
    for (P p : pts) {
        pts_y[p.y].insert(p.x);
    }
    rep(y,0,H) {
        pts_y[y].insert(W);
    }
    ll ans = numeric_limits<ll>::max();
    ll left = 0;
    rep(y,0,H) {
        while (pts_y[y].find(left) != pts_y[y].end()) {
            left++;
        }
        if (left >= W) {
            break;
        }
        auto it = pts_y[y].upper_bound(left);
        ll ans_loc = *it;
        ans = min(ans, ans_loc);
        left++;
    }
    cout << ans << endl;
}
