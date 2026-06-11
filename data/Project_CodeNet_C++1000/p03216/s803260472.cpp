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
    ll N;
    cin >> N;
    string s;
    cin >> s;
    vector<ll> m_cnt(N+1);
    rep(n,1,N+1) {
        m_cnt[n] = m_cnt[n-1];
        if (s[n-1] == 'M') {
            m_cnt[n]++;
        }
    }
    vector<ll> c_cnt(N+1);
    rep(n,1,N+1) {
        c_cnt[n] = c_cnt[n-1];
        if (s[n-1] == 'C') {
            c_cnt[n]++;
        }
    }
    vector<ll> mc_cnt(N+1);
    rep(n,1,N+1) {
        mc_cnt[n] = mc_cnt[n-1];
        if (s[n-1] == 'C') {
            mc_cnt[n] += m_cnt[n];
        }
    }
    ll Q;
    cin >> Q;
    rep(i,0,Q) {
        ll k;
        cin >> k;
        ll ans = 0;
        rep(i,0,N) {
            if (s[i] != 'D') {
                continue;
            } else {
                ll e = min(i+k, N);
                ans += (mc_cnt[e] - mc_cnt[i]) - (c_cnt[e] - c_cnt[i]) * m_cnt[i];
            }
        }
        cout << ans << endl;
    }
}

