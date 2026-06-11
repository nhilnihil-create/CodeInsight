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
    ll N;
    cin >> N;
    vector<ll> Ais(N);
    rep(i,0,N) {
        cin >> Ais[i];
    }
    vector<ll> sum(N+1);
    rep(n,1,N+1) {
        sum[n] = sum[n-1] + Ais[n-1];
    }
    vector<ll> good_divide_left(N);
    ll left = 1;
    rep(n,2,N-2+1) {
        while (left+1 <= n-1
               && abs(sum[left] - (sum[n]-sum[left])) > abs(sum[left+1] - (sum[n]-sum[left+1]))) {
            left++;
        }
        good_divide_left[n] = left;
    }
    vector<ll> good_divide_right(N);
    ll right = 1;
    rrep(n,N-2+1,2) {
        while (right+1 <= N-n-1
               && abs((sum[N]-sum[N-right])-(sum[N-right]-sum[n])) > abs((sum[N]-sum[N-(right+1)])-(sum[N-(right+1)]-sum[n]))) {
            right++;
        }
        good_divide_right[n] = right;
    }
    ll ans = numeric_limits<ll>::max();
    rep(n,2,N-2+1) {
        ll left = good_divide_left[n];
        ll right = good_divide_right[n];
        vector<ll> nums = {sum[left], sum[n] - sum[left], sum[N] - sum[N-right], sum[N-right] - sum[n]};
        ans = min(ans, *max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end()));
    }
    cout << ans << endl;
}

