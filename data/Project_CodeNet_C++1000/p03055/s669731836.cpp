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

struct Edge {
	ll from;
	ll to;
};

ll max_path(const vector<vector<Edge>>& graph, ll v, ll* out_depth, vector<bool>& visited) {
	visited[v] = true;
	ll ans = numeric_limits<ll>::min();
	vector<ll> depths;
	for (Edge e : graph[v]) {
		if (visited[e.to]) {
			continue;
		}
		ll mp, depth;
		mp = max_path(graph, e.to, &depth, visited);
		ans = max(ans, mp);
		depths.push_back(depth);
	}
	if (depths.size() >= 2) {
		sort(depths.rbegin(), depths.rend());
		ans = max(ans, depths[0] + depths[1] + 2);
		*out_depth = depths[0] + 1;
	} else if (depths.size() == 1) {
		ans = max(ans, depths[0] + 1);
		*out_depth = depths[0] + 1;
	} else {
		ans = max(ans, (ll)0);
		*out_depth = 0;
	}
	return ans;
}

int main() {
	ll N;
	cin >> N;
	vector<vector<Edge>> graph(N);
	rep(i,0,N-1) {
		ll A, B;
		cin >> A >> B;
		A--;
		B--;
		graph[A].push_back({A, B});
		graph[B].push_back({B, A});
	}
	vector<bool> visited(N);
	ll depth;
	ll len = max_path(graph, 0, &depth, visited);
	// cout << len << endl;
	// cout << depth << endl;
	if (len % 3 == 1) {
		cout << "Second" << endl;
	} else {
		cout << "First" << endl;
	}
}
