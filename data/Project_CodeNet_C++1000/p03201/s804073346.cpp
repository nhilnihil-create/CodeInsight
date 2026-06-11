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
    vector<ll> Ais;
    for (ll i = 0; i < N; i++) {
        ll Ai;
        cin >> Ai;
        Ais.push_back(Ai);
    }
    sort(Ais.rbegin(), Ais.rend());
    unordered_map<ll, ll> first_idx;
    for (ll i = 0; i < N; i++) {
        if (first_idx.find(Ais[i]) == first_idx.end()) {
            first_idx[Ais[i]] = i;
        }
    }
    vector<ll> table(N);
    ll ans = 0;
    for (ll i = 0; i < N; i++) {
        bool used = false;
        if (table[i] > 0) {
            ans += 1;
            table[i]--;
            used = true;
        }
        if (i < N - 1 && Ais[i] == Ais[i+1]) {
            table[i+1] += table[i];
            first_idx[Ais[i]] = i+1;
        }
        if (!used) {
            ll pot = 1;
            while (pot <= Ais[i]) {
                pot *= 2;
            }
            ll rest = pot - Ais[i];
            if (first_idx.find(rest) != first_idx.end()) {
                table[first_idx[rest]]++;
            }
        }
    }
    cout << ans << endl;
}