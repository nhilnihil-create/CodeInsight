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

#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a-1;i>=b;i--)

int main() {
    vector<ll> cnt_matches_vec = {2, 5, 5, 4, 5, 6, 3, 7, 6};
    unordered_map<ll, ll> cnt_matches;
    rep(i, 0, 9) {
        cnt_matches[i+1] = cnt_matches_vec[i];
    }
    ll N, M;
    cin >> N >> M;
    vector<ll> Ais(M);
    rep(i, 0, M) {
        cin >> Ais[i];
    }
    {
        unordered_map<ll, ll> map;
        rep(i, 0, Ais.size()) {
            if (map.find(cnt_matches[Ais[i]]) == map.end()) {
                map[cnt_matches[Ais[i]]] = Ais[i];
            } else {
                map[cnt_matches[Ais[i]]] = max(map[cnt_matches[Ais[i]]], Ais[i]);
            }
        }
        Ais.clear();
        for (const auto& kv : map) {
            Ais.push_back(kv.second);
        }
    }
    sort(Ais.begin(), Ais.end());
    auto dp = make_vec_nd(numeric_limits<ll>::min(), Ais.size()+1, N+1);
    dp[0][0] = 0;
    rep(number_cnt, 1, Ais.size()+1) {
        ll cost = cnt_matches[Ais[number_cnt-1]];
        rep(n, 0, N+1) {
            dp[number_cnt][n] = dp[number_cnt-1][n];
            if (n >= cost) {
                dp[number_cnt][n] = max(dp[number_cnt][n],
                                        dp[number_cnt][n-cost] + 1);
            }
        }
    }
    vector<ll> digits;
    ll N_loc = N;
    rrep(number_cnt,Ais.size()+1,1) {
        ll cost = cnt_matches[Ais[number_cnt-1]];;
        while(N_loc-cost >= 0 &&
              dp[number_cnt][N_loc] == dp[number_cnt][N_loc-cost]+1) {
            digits.push_back(Ais[number_cnt-1]);
            N_loc -= cost;
        }
    }
    sort(digits.rbegin(), digits.rend());
    rep(i,0,digits.size()) {
        cout << digits[i];
    }
    cout << endl;
}
