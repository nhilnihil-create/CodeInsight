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

int main() {
    ll H, W;
    cin >> H >> W;
    auto is_black = make_vec_nd(false, W, H);
    rep(y,0,H) {
        rep(x,0,W) {
            char c;
            cin >> c;
            is_black[x][y] = (c == '#');
        }
    }
    struct Point {
        ll x;
        ll y;
        ll encode() {
            return (y << 32) | x;
        }
        Point(ll x, ll y) : x(x), y(y) {}
        static Point decode(ll code) {
            ll x = code & (((ll)1 << 32) - 1);
            ll y = (code >> 32) & (((ll)1 << 32) - 1);
            return Point{x, y};
        }
        Point operator+(const Point& rhs) const {
            return Point{x + rhs.x, y + rhs.y};
        }
    };
    vector<Point> vecs;
    vecs.emplace_back(-1, 0);
    vecs.emplace_back(1, 0);
    vecs.emplace_back(0, -1);
    vecs.emplace_back(0, 1);
    auto in_rect = [H, W] (Point p) {
        return 0 <= p.x && p.x < W && 0 <= p.y && p.y < H;
    };
    unordered_set<ll> filled;
    unordered_set<ll> seeds;
    rep(x,0,W) {
        rep(y,0,H) {
            if (is_black[x][y]) {
                Point p{x, y};
                filled.insert(p.encode());
                for (const Point& vec : vecs) {
                    Point q = p + vec;
                    if (in_rect(q) && filled.count(q.encode()) == 0) {
                        seeds.insert(q.encode());
                    }
                }
            }
        }
    }
    auto print = [&filled, &seeds, H, W](){
        rep(y,0,H) {
            rep(x,0,W) {
                Point p(x, y);
                if (filled.count(p.encode()) > 0) {
                    cout << '#';
                } else if (seeds.count(p.encode()) > 0) {
                    cout << '@';
                } else {
                    cout << '.';
                }
            }
            cout << endl;
        }
    };
    ll cnt = 0;
//    cout << "start: " << endl;
//    print();
    while (filled.size() < W * H) {
        cnt++;
        for (ll p_enc : seeds) {
            filled.insert(p_enc);
        }
        unordered_set<ll> new_seeds;
        for (ll p_enc : seeds) {
            Point p = Point::decode(p_enc);
            for (const Point& vec : vecs) {
                Point q = p + vec;
                if (in_rect(q) && filled.count(q.encode()) == 0) {
                    new_seeds.insert(q.encode());
                }
            }
        }
        swap(seeds, new_seeds);
//        cout << "cnt: " << cnt << endl;
//        print();
    }
    cout << cnt << endl;
}
