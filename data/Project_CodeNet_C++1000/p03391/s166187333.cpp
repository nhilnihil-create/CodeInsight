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
// template<class T> T gabs(const T& x) { return max(x, -x); }
// #define abs gabs

int main() {
    int n;
    cin >> n;
    vector<i64> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    if (a == b) {
        cout << 0 << endl;
        return 0;
    }

    i64 sum = 0, min_b = 1ll << 50;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        if (a[i] > b[i]) {
            min_b = min(min_b, b[i]);
        }
    }

    cout << sum - min_b << endl;
    return 0;
}