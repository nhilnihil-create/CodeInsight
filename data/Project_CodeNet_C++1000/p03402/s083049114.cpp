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
    int a, b;
    cin >> a >> b;
    vector<string> s(40);
    for (int i = 0; i < 40; ++i) {
        s[i] = string(100, i < 20 ? '#' : '.');
    }

    for (int k = 0; k < 2; ++k) {
        for (int c = 0; c < (k == 0 ? a : b) - 1; ++c) {
            int i = c / 50 * 2 + (k == 1 ? 21 : 0), j = c % 50 * 2;
            s[i][j] = k == 0 ? '.' : '#';
        }
    }

    cout << "40 100\n";
    for (auto t : s) cout << t << '\n';
    return 0;
}