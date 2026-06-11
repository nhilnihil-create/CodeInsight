#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#include <stack>
#include <functional>

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...)
#endif

#define rep_(i, a_, b_, a, b, ...) for (int i = (a), i##_len = (b); i < i##_len; ++i)
#define rep(i, ...) rep_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define reprev_(i, a_, b_, a, b, ...) for (int i = (b-1), i##_min = (a); i >= i##_min; --i)
#define reprev(i, ...) reprev_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define all(x) (x).begin(), (x).end()
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
#define fls(x) (64 - __builtin_clzll(x))
#define pcnt(x) __builtin_popcountll(x)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> P;
typedef long double ld;

int main (void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<vector<int>> c(3, vector<int>(3));
    rep (i, 3) rep (j, 3) cin >> c[i][j];
    bool ok = true;
    rep (i1, 3) {
        rep (i2, 3) {
            rep (j1, 3) {
                rep (j2, 3) {
                    if (i1 == i2 || j1 == j2) continue;
                    int p = c[i1][j1], q = c[i1][j2],
                        r = c[i2][j1], s = c[i2][j2];
                    if (q - p != s - r || r - p != s - q) ok = false;
                }
            }
        }
    }
    cout << (ok ? "Yes\n" : "No\n");
    return 0;
}