//
// main.cpp
//

#include <algorithm>
#include <array>
#include <assert.h>
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
	vector<ll> ts(N);
	rep(i,0,N) {
		cin >> ts[i];
	}
	vector<ll> ts_sums(N+1);
	rep(i,1,N+1) {
		ts_sums[i] = ts_sums[i-1] + ts[i-1];
	}
	vector<ll> vs(N);
	rep(i,0,N) {
		cin >> vs[i];
	}
	vector<ll> max_speed(N+1, numeric_limits<ll>::max());
	max_speed[0] = 0;
	max_speed[N] = 0;
	rep(i,0,N) {
		max_speed[i] = min(max_speed[i], vs[i]);
		max_speed[i+1] = min(max_speed[i+1], vs[i]);
	}
	rep(i,0,N+1) {
		rep(j,0,N+1) {
			max_speed[j] = min(max_speed[j],
							   max_speed[i] + abs(ts_sums[i]-ts_sums[j]));
		}
	}
	/*
	rep(i,0,N+1) {
		cout << "max_speed[" << i << "] = " << max_speed[i] << endl;
	}
	*/
	double ans = 0;
	rep(i,0,N) {
		double ans_loc = 0;
		double x = (-max_speed[i] + max_speed[i+1] + ts[i]) / 2.0;
		double y = (max_speed[i] + max_speed[i+1] + ts[i]) / 2.0;
		if (y < vs[i]) {
			ans_loc += x * (max_speed[i] + y) / 2.0;
			ans_loc += (ts[i] - x) * (max_speed[i+1] + y) / 2.0;
		} else {
			double x0 = vs[i] - max_speed[i];
			double x1 = -vs[i] + max_speed[i+1] + ts[i];
			ans_loc += x0 * (max_speed[i] + vs[i]) / 2.0;
			ans_loc += (x1 - x0) * vs[i];
			ans_loc += (ts[i] - x1) * (vs[i] + max_speed[i+1]) / 2.0;
		}
		ans += ans_loc;
	}
	cout << fixed << setprecision(10) << ans << endl;
}
