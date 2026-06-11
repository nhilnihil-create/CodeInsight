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

#define rep(i,a,b) for(ll i=(a);i<(b);i++)
#define rrep(i,a,b) for(ll i=(a)-1;i>=(b);i--)

int main() {
    ll N, K;
    cin >> N >> K;
    struct Sushi {
        ll id;
        ll t;
        ll d;
        static bool comp(Sushi lhs, Sushi rhs) {
            return lhs.d > rhs.d || (lhs.d == rhs.d && lhs.id < rhs.id);
        }
    };
    vector<Sushi> sushis(N);
    rep(i,0,N) {
        cin >> sushis[i].t >> sushis[i].d;
        sushis[i].id = i;
    }
    unordered_map<ll, Sushi> most_delicious;
    rep(i,0,N) {
        ll t = sushis[i].t;
        ll d = sushis[i].d;
        if (most_delicious.find(t) == most_delicious.end() || most_delicious[t].d < d) {
            most_delicious[t] = sushis[i];
        }
    }
    vector<Sushi> most_deli_vec;
    for (const auto& kv : most_delicious) {
        most_deli_vec.push_back(kv.second);
    }
    ll type_cnt = most_deli_vec.size();
    sort(most_deli_vec.begin(), most_deli_vec.end(), Sushi::comp);
    sort(sushis.begin(), sushis.end(), Sushi::comp);
    set<Sushi, decltype(&Sushi::comp)> top(&Sushi::comp);
    ll top_sum = 0;
    rep(i,0,K) {
        top.insert(sushis[i]);
        top_sum += sushis[i].d;
    }
    ll ans = top_sum;
    ll types_ensure_sum = 0;
    rep(x,1,min(K, type_cnt)+1) {
        Sushi add = most_deli_vec[x-1];
        types_ensure_sum += add.d;
        if (top.find(add) != top.end()) {
            top.erase(add);
            top_sum -= add.d;
        } else {
            auto back = prev(top.end());
            top_sum -= back->d;
            top.erase(back);
        }
        ll ans_loc = x * x + types_ensure_sum + top_sum;
        ans = max(ans, ans_loc);
    }
    cout << ans << endl;
}

