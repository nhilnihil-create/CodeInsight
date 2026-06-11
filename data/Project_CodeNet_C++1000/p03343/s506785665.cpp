//
//  main.cpp
//

#include <algorithm>
#include <array>
#include <assert.h>
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

int main() {
    ll N, K, Q;
    cin >> N >> K >> Q;
    vector<ll> As(N);
    rep(i,0,N) {
        cin >> As[i];
    }
    vector<ll> Bs = As;
    sort(Bs.begin(), Bs.end());
    ll ans = numeric_limits<ll>::max();
    for (ll b : Bs) {
        using Queue = priority_queue<ll, vector<ll>, greater<ll>>;
        auto compare_queue = [](Queue& lhs, Queue& rhs){ return lhs.top() > rhs.top(); };
        priority_queue<Queue, vector<Queue>, decltype(compare_queue)> groups(compare_queue);
        ll i = 0;
        while (i < N) {
            Queue queue;
            while (i < N && As[i] >= b) {
                queue.push(As[i]);
                i++;
            }
            if (queue.size() >= K) {
                groups.push(move(queue));
            }
            i++;
        }
        ll cnt = 0;
        ll mn = numeric_limits<ll>::max();
        ll mx = numeric_limits<ll>::min();
        while (groups.size() > 0) {
            cnt++;
            Queue moved = (Queue&&)groups.top();
            groups.pop();
            ll elem = moved.top();
            mn = min(mn, elem);
            mx = max(mx, elem);
            moved.pop();
            if (moved.size() >= K) {
                groups.push(move(moved));
            }
            if (cnt >= Q) {
                break;
            }
        }
        if (cnt >= Q) {
            ans = min(ans, mx - mn);
        }
    }
    cout << ans << endl;
}
