//
//  main.cpp
//

#include <algorithm>
#include <array>
#include <assert.h>
#include <iomanip>
#include <iostream>
#include <limits>
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

template<typename T>
vector<T> make_vec_nd(T init, size_t size) {
	return vector<T>(size, init);
}
template<typename T, typename... Args>
auto make_vec_nd(T init, size_t size, Args... rest) {
	auto inner = make_vec_nd(init, rest...);
	return vector<decltype(inner)>(size, inner);
}

int main() {
	ll N;
	cin >> N;
	struct Block {
		ll weight;
		ll strength;
		ll value;
	};
	vector<Block> blocks;
	for (ll i = 0; i < N; i++) {
		Block b;
		cin >> b.weight >> b.strength >> b.value;
		blocks.push_back(b);
	}
	sort(blocks.begin(), blocks.end(), [](Block lhs, Block rhs) {
		return lhs.weight + lhs.strength < rhs.weight + rhs.strength;
	});
    auto dp = make_vec_nd(numeric_limits<ll>::min(), blocks.size()+1, 20001);
    dp[0][0] = 0;
    for (ll n = 1; n < blocks.size()+1; n++) {
        for (ll w = 0; w <= 20000; w++) {
            dp[n][w] = dp[n-1][w];
            if (blocks[n-1].weight <= w && w - blocks[n-1].weight <= blocks[n-1].strength) {
                dp[n][w] = max(dp[n][w], dp[n-1][w - blocks[n-1].weight] + blocks[n-1].value);
            }
        }
    }
    ll ans = numeric_limits<ll>::min();
    for (ll w = 0; w <= 20000; w++) {
        ans = max(ans, dp[N][w]);
    }
    cout << ans << endl;
}
