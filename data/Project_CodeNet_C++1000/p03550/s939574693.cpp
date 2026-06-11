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
    ll N, Z, W;
    cin >> N >> Z >> W;
    vector<ll> ais;
    for (ll i = 0; i < N; i++) {
        ll ai;
        cin >> ai;
        ais.push_back(ai);
    }
    ais.insert(ais.begin(), W);
    vector<ll> dp_x(ais.size(), numeric_limits<ll>::min());
    vector<ll> dp_y(ais.size(), numeric_limits<ll>::max());
    for (ll i = ais.size() - 1; i >= 1; i--) {
        for (ll j = i; j < ais.size(); j++) {
            if (j == ais.size() - 1) {
                dp_x[i] = max(dp_x[i], abs(ais[i-1] - ais[j]));
                dp_y[i] = min(dp_y[i], abs(ais[i-1] - ais[j]));
            } else {
                dp_x[i] = max(dp_x[i], dp_y[j+1]);
                dp_y[i] = min(dp_y[i], dp_x[j+1]);
            }
        }
    }
    cout << dp_x[1] << endl;
}

