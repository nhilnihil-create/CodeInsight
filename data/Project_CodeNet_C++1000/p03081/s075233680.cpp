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
	ll N, Q;
	cin >> N >> Q;
	string s;
	cin >> s;
	struct Query {
		char t;
		char d;
	};
	vector<Query> queries(Q);
	rep(i,0,Q) {
		cin >> queries[i].t >> queries[i].d;
	}
	ll left_end = 0;
	ll right_end = N-1;
	rrep(i,Q,0) {
		Query q = queries[i];
		if (q.d == 'R' && s[right_end] == q.t) {
			right_end--;
		}
		if (right_end < N-1 && q.d == 'L' && s[right_end+1] == q.t) {
			right_end++;
		}
		if (q.d == 'L' && s[left_end] == q.t) {
			left_end++;
		}
		if (left_end > 0 && q.d == 'R' && s[left_end-1] == q.t) {
			left_end--;
		}
		if (right_end < left_end) {
			cout << 0 << endl;
			return 0;
		}
	}
	cout << N - left_end - (N-1 - right_end) << endl;
}

