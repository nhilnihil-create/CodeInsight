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

ll digit_sum(ll val) {
    ll ret = 0;
    while (val > 0) {
        ret += val % 10;
        val /= 10;
    }
    return ret;
}

int main() {
    ll K;
    cin >> K;
    vector<ll> ans;
    ll pow = 1;
    for (ll k = 0; k < 16; k++) {
        for (ll n = 1;; n++) {
            ll val = n * pow + (pow - 1);
            if (val >= (k+1)*pow*10) {
                break;
            }
            if (ans.size() == 0 || ans.back() < val) {
                ans.push_back(val);
            }
        }
        pow *= 10;
    }
    ll cnt = 0;
    rep(i,0,ans.size()) {
        ll n = ans[i];
        bool ok = true;
        rep(j,i+1,ans.size()) {
            ll m = ans[j];
            if ((__int128)n * (__int128)digit_sum(m) > (__int128)m * (__int128)digit_sum(n)) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << n << endl;
            cnt++;
            if (cnt == K) {
                break;
            }
        }
    }
}

