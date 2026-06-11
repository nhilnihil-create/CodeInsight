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

ll count_zero_below(ll k, ll x) {
    ll ans = 0;
    ans += (x / ((ll)1 << (k+1))) * ((ll)1 << k);
    ans += min(x % ((ll)1 << (k+1)), ((ll)1 << k));
    return ans;
}

ll xor_below(ll x) {
    ll ans = 0;
    rep(k,0,63) {
        ll zero_cnt = count_zero_below(k, x);
        ll one_cnt = x - zero_cnt;
        if (one_cnt % 2 == 1) {
            ans += (ll)1 << k;
        }
    }
    return ans;
}

int main() {
    ll A, B;
    cin >> A >> B;
    cout << (xor_below(A) ^ xor_below(B+1)) << endl;
}
