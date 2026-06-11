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

struct Mod {
	static ll BASE;
	ll value = 0;
	static ll residue(ll value) { return (value % BASE + BASE) % BASE; }
	Mod()
	: value(0) {}
	Mod(ll value)
	: value(residue(value)) {}
	Mod operator+(const Mod& rhs) const { return Mod(value + rhs.value); }
	void operator+=(const Mod& rhs) { *this = *this + rhs; }
	Mod operator-(const Mod& rhs) const { return Mod(value - rhs.value); }
	void operator-=(const Mod& rhs) { *this = *this - rhs; }
	Mod operator*(const Mod& rhs) const { return Mod(value * rhs.value); }
	void operator*=(const Mod& rhs) { *this = *this * rhs; }
};
ll Mod::BASE = 1000000007;

int main() {
	ll N;
	cin >> N;
	vector<ll> cols;
	rep(i,0,N) {
		ll c;
		cin >> c;
		c--;
		if (cols.size() == 0 || cols.back() != c) {
			cols.push_back(c);
		}
	}
	N = cols.size();
	unordered_map<ll, Mod> memo;
	Mod ans = 1;
	rep(i,0,N) {
		Mod bak = memo[cols[i]];
		memo[cols[i]] += ans;
		ans += bak;
	}
	cout << ans.value << endl;
}
