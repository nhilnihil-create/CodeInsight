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
    ll N;
    cin >> N;
    vector<ll> As(N);
    rep(i,0,N) {
        cin >> As[i];
    }
    if (N == 1) {
        cout << 1 << endl;
        return 0;
    }
    auto is_ok = [&As, N](ll n) {
        if (n == 1) {
            rep(i,1,N) {
                if (As[i] <= As[i-1]) {
                    return false;
                }
            }
            return true;
        }
        map<ll, ll> digits;
        rep(i,1,N) {
            if (As[i] <= As[i-1]) {
                ll d = As[i] - 1;
                digits.erase(digits.upper_bound(d), digits.end());
                digits[d]++;
                while (digits[d] >= n) {
                    if (d == 0) {
                        return false;
                    }
                    digits.erase(d);
                    d--;
                    digits[d]++;
                }
            }
        }
        return true;
    };
    ll ng = 1;
    ll ok = 1;
    while (is_ok(ok) == false) {
        ok *= 2;
    }
    while (ok - ng >= 2) {
        ll mid = (ng + ok) / 2;
        if (is_ok(mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    cout << ok << endl;
}

/*
 
 1
 1
 
 2
 1 1
 
 3
 1 1 1
 
 4
 1 1 1 1
 
 1
 2
 
 2
 2 2
 
 3
 2 2 2
 
 4
 2 2 2 2
 
 5
 2 2 2 2 2
 
 */
