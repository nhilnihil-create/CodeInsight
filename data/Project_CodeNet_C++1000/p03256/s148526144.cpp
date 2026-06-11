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

bool is_loop(ll now, vector<vector<ll>>& graph, vector<ll>& state) {
    state[now] = 1;
    for (ll to : graph[now]) {
        if (state[to] == 1) {
            return true;
        }
        if (state[to] == 2) {
            continue;
        }
        if (is_loop(to, graph, state)) {
            return true;
        }
    }
    state[now] = 2;
    return false;
}

int main() {
    ll N, M;
    cin >> N >> M;
    string s;
    cin >> s;
    vector<vector<ll>> graph(2 * N);
    rep(i,0,M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        if (s[a] == s[b]) {
            graph[2*a+0].push_back(2*b+1);
            graph[2*b+0].push_back(2*a+1);
        } else {
            graph[2*a+1].push_back(2*b+0);
            graph[2*b+1].push_back(2*a+0);
        }
    }
    vector<ll> state(2 * N);
    rep(i,0,2*N) {
        if (state[i] == 2) {
            continue;
        }
        if (is_loop(i, graph, state)) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
