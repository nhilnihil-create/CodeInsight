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

#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a-1;i>=b;i--)

int main() {
	ll H, W, N;
	cin >> H >> W >> N;
	ll sx, sy;
	cin >> sy >> sx;
	sx--;
	sy--;
	string S, T;
	cin >> S >> T;
	struct I {
		ll l;
		ll r;
		ll u;
		ll d;
	};
	I is_no = {};
	T.pop_back();
	ll n = S.size()+T.size();
	rep(i,0,n) {
		if (i % 2 == 0) {
			char c = S.back();
			S.pop_back();
			if (c == 'L') {
				is_no.l++;
			} else if (c == 'R') {
				is_no.r++;
			} else if (c == 'U') {
				is_no.u++;
			} else {
				is_no.d++;
			}
		} else {
			char c = T.back();
			T.pop_back();
			if (c == 'L') {
				is_no.r--;
			} else if (c == 'R') {
				is_no.l--;
			} else if (c == 'U') {
				is_no.d--;
			} else {
				is_no.u--;
			}
		}
		is_no.l = max((ll)0, min(W, is_no.l));
		is_no.r = max((ll)0, min(W, is_no.r));
		is_no.u = max((ll)0, min(H, is_no.u));
		is_no.d = max((ll)0, min(H, is_no.d));
		if (is_no.l + is_no.r >= W || is_no.u + is_no.d >= H) {
			cout << "NO" << endl;
			return 0;
		}
		// cout << i << ": " << is_no.l << " " << is_no.r << " " << is_no.u << " " << is_no.d << endl;
	}
	if (sx < is_no.l || sy < is_no.u || W-sx-1 < is_no.r || H-sy-1 < is_no.d) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
	}
}
