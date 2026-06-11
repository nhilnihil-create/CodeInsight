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

int f (int i, int p) {
    return -(i / p * p) + i % p;
}

int main (void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, a, b; cin >> n >> a >> b;
    if (a + b > n + 1 || a * b < n) {
        cout << "-1\n";
        return 0;
    }

    rep (i, n - a, n) cout << i + 1 << " \n"[a == n && i == i_len - 1];
    if (a >= n) return 0;
    int t = n - a;
    rep (i, b - 1) {
        int k = (n - a) / (b - 1) + (i % (b - 1) < (n - a) % (b - 1));
        rep (j, t - k, t) cout << j + 1 << " ";
        t -= k;
    }
    cout << "\n";
    return 0;
}