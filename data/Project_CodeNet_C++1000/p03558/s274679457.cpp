// 見せてやるぜ、奇跡ってやつをよぉ……
#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <cmath>
#include <complex>
#include <deque>
#include <iterator>
#include <numeric>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <limits>
#include <iomanip>
#include <functional>
#include <cassert>
// using namespace std;

// using ll=long long;
// template<class T> using V = vector<T>;
// template<class T, class U> using P = pair<T, U>;
// using vll = V<ll>;
// using vvll = V<vll>;
// #define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
// #define REP(i, n) rep(i, 0, n)
// #define ALL(v) v.begin(),v.end()
// template < class T > inline bool chmax(T& a, T b) {if (a < b) { a=b; return true; } return false; }
// template < class T > inline bool chmin(T& a, T b) {if (a > b) { a=b; return true; } return false; }
// #define DEBUG_VLL(vec) REP(sz, vec.size()) cerr<<vec[sz]<<(sz==vec.size()-1?'\n':' ');

// const ll MOD = 1000000007;
// const ll HIGHINF = (ll)1e18;

const int INF = 1e9;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int k;
    std::cin >> k;
    std::vector< std::vector< std::pair<int, int> > > edges(k);
    for (int i = 0; i < k; i++) {
        edges[i].emplace_back((i + 1) % k, 1);
        if (i != 10 * i % k) edges[i].emplace_back(10 * i % k, 0);
    }

    std::deque<int> deq;
    std::vector<int> d(k, INF);
    d[1] = 0;
    deq.emplace_back(1);
    while (!deq.empty()) {
        int v = deq.front(); deq.pop_front();
        for (std::pair<int, int> e: edges[v]) {
            if (d[e.first] > d[v] + e.second) {
                d[e.first] = d[v] + e.second;
                if (e.second == 0) deq.emplace_front(e.first);
                else deq.emplace_back(e.first);
            }
        }
    }

    std::cout << d[0] + 1 << '\n';
    return 0;
}

