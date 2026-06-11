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
    string s;
    cin >> s;
    unordered_map<int, ll> min_at_vec;
    auto get_min_at_vec = [&min_at_vec](int vec) -> ll {
        if (min_at_vec.find(vec) == min_at_vec.end()) {
            return numeric_limits<ll>::max();
        } else {
            return min_at_vec[vec];
        }
    };
    min_at_vec[0] = 0;
    int vec = 0;
    rep(i,0,s.size()) {
        ll ans_loc = numeric_limits<ll>::max();
        vec ^= (1 << (s[i] - 'a'));
        ans_loc = min(ans_loc, get_min_at_vec(vec));
        rep(ch,0,26) {
            int vec_loc = vec ^ (1 << ch);
            ans_loc = min(ans_loc, get_min_at_vec(vec_loc));
        }
        ans_loc++;
        min_at_vec[vec] = min(get_min_at_vec(vec), ans_loc);
        if (i == s.size() - 1) {
            cout << ans_loc << endl;
        }
    }
}
