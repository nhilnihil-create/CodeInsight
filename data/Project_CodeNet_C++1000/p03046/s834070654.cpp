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

i64 m, k;
int main() {
    cin >> m >> k;
    
    if (k >= (1 << m) || (k == 1 && m == 1)) {
        cout << -1 << endl;
        return 0;
    }

    if (m == 1 && k == 0) {
        cout << "0 0 1 1\n";
        return 0;
    }

    vector<int> a;
    for (int i = 0; i < (1 << m); ++i) {
        if (i == k) continue;
        a.push_back(i);
    }
    auto b = a;
    reverse(begin(b), end(b));
    for (int x : a) cout << x << ' ';
    cout << k << ' ';
    for (int x : b) cout << x << ' ';
    cout << k << '\n';
    return 0;
}