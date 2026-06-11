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
vector<T> make_vec_nd(T init, ll size) {
    return vector<T>(size, init);
}
template<typename T, typename... Args>
auto make_vec_nd(T init, ll size, Args... rest) {
    auto inner = make_vec_nd(init, rest...);
    return vector<decltype(inner)>(size, inner);
}

#define rep(i,a,b) for(ll i=(a);i<(b);i++)
#define rrep(i,a,b) for(ll i=(a)-1;i>=(b);i--)

int main() {
    ll K;
    cin >> K;
    vector<ll> Ais(K);
    rep(i,0,K) {
        cin >> Ais[i];
    }
    ll start = 2;
    ll last = 2;
    rrep(i,K,0) {
        ll Ai = Ais[i];
        start = (start / Ai + (start % Ai != 0)) * Ai;
        last = (last / Ai) * Ai + (Ai - 1);
        if (last < start) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << start << " " << last << endl;
}

