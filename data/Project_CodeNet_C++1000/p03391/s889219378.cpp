//
//  main.cpp
//
 
#include <algorithm>
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <iomanip>
#include <limits>
#include <map>
#include <math.h>
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
 
using ll = long long;
using ull = unsigned long long;
 
template<typename T>
vector<T> make_vec_nd(T init, size_t size) {
	return vector<T>(size, init);
}
template<typename T, typename... Args>
auto make_vec_nd(T init, size_t size, Args... rest) {
	auto inner = make_vec_nd(init, rest...);
	return vector<decltype(inner)>(size, inner);
}

#define rep(i,a,b) for(ll i=(a);i<(b);i++)
#define rrep(i,a,b) for(ll i=(a)-1;i>=(b);i--)

int main() {
	ll N;
	cin >> N;
	vector<ll> As(N);
	vector<ll> Bs(N);
	ll sum = 0;
	ll b_mn = numeric_limits<ll>::max();
	rep(i,0,N) {
		ll A, B;
		cin >> A >> B;
		sum += A;
		if (A > B) {
			b_mn = min(b_mn, B);
		}
	}
	if (b_mn == numeric_limits<ll>::max()) {
		cout << 0 << endl;
	} else {
		cout << sum - b_mn << endl;
	}
}
