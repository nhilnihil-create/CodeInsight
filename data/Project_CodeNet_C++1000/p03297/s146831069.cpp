#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <array>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <complex>
#include <cstdint>
#include <cassert>
#include <random>

using namespace std;
using i64 = int64_t;
using i32 = int32_t;
template<class T, class U> void init_n(vector<T>& v, size_t n, U x) 
{ v = vector<T>(n, x); }
template<class T> void init_n(vector<T>& v, size_t n) { init_n(v, n, T()); }
template<class T> void read_n(vector<T>& v, size_t n, size_t o = 0) 
{ v = vector<T>(n+o); for (size_t i=o; i<n+o; ++i) cin >> v[i]; }
template<class T> void read_n(T a[], size_t n, size_t o = 0)
{ for (size_t i=o; i<n+o; ++i) cin >> a[i]; }
template<class T> T iabs(const T& x) { return max(x, -x); }
// #define abs gabs

i64 gcd(i64 x, i64 y) {
    while (x % y != 0) {
        swap(x, y);
        y %= x;
    }
    return y;
}

bool solve() {
    i64 a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a < b || d < b) {
        return false;
    }
    if (c >= b) {
        return true;
    }
    i64 g = gcd(b, d);
    return (b - g + a % g) % b <= c;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        if (solve()) cout << "Yes\n"; else cout << "No\n";
    }
    return 0;
}
