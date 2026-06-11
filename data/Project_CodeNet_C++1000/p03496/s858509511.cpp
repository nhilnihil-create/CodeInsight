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
template<class T> T iabs(const T& x) { return max(x, -x); }
// #define abs gabs

int main() {
    int n;
    cin >> n;
    vector<i64> a(n);
    int mi = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (iabs(a[i]) > iabs(a[mi])) {
            mi = i;
        }
    }

    vector<pair<int, int>> res;
    for (int i = 0; i < n; ++i) {
        if (i != mi) {
            res.emplace_back(mi, i);
            a[i] += a[mi];
        }
        cerr << a[i] << ' ';
    }
    cerr << endl;

    if (a[mi] > 0) {
        for (int i = 0; i < n - 1; ++i) {
            res.emplace_back(i, i + 1);
            a[i + 1] += a[i];
        }
    } else {
        for (int i = n - 2; i >= 0; --i) {
            res.emplace_back(i + 1, i);
            a[i] += a[i + 1];
        }
    }
    for (int i = 0; i < n; ++i) {
        cerr << a[i] << ' ';
    }
    cerr << endl;

    cout << res.size() << endl;
    for (auto p : res) {
        cout << p.first + 1 << ' ' << p.second + 1 << '\n';
    }
    return 0;
}