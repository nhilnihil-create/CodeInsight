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
	ll L;
	cin >> L;
	if (L == 2) {
		cout << "2 2" << endl;
		cout << "1 2 0" << endl;
		cout << "1 2 1" << endl;
		return 0;
	}
	ll max_val = L-1;
	ll max_bit = 0;
	rep(i,0,32) {
		if (max_val & ((ll)1 << i)) {
			max_bit = i;
		}
	}
	struct Edge {
		ll from;
		ll to;
		ll cost;
	};
	vector<Edge> graph;
	ll N = max_bit + 1;
	rep(i,0,N-1) {
		graph.push_back({i, i+1, 0});
		graph.push_back({i, i+1, (ll)1 << (N-2-i)});
	}
	rrep(i,max_bit,0) {
		if ((max_val & ((ll)1 << i)) == 0) {
			continue;
		}
		ll v = max_val - ((((ll)1 << (i+1)) - 1) & max_val);
		graph.push_back({0, N-1-i, v});
	}
	graph.push_back({0, N-1, max_val});
	ll M = graph.size();
	cout << N << " " << M << endl;
	rep(i,0,M) {
		cout << graph[i].from + 1 << " " << graph[i].to + 1 << " " << graph[i].cost << endl;
	}
}

