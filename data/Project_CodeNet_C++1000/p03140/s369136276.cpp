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
    string s[3];
    for (int i = 0; i < 3; ++i) cin >> s[i];
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        set<char> st;
        for (int j = 0; j < 3; ++j) {
            st.insert(s[j][i]);
        }
        ans += st.size() - 1;
    }
    cout << ans << endl;
    return 0;
}
