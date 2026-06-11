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
    int n; cin >> n;
    vector<ll> a(n), sum(n + 1);
    rep (i, n) {
        cin >> a[i];
        sum[i + 1] = sum[i] + a[i];
    }
    ll ans = (ll)1e18;
    rep (i, 2, n - 1) {
        ll m, M;
        int ok = 0, ng = i;
        while (ng - ok > 1) {
            int med = (ng + ok) / 2;
            (sum[med] <= sum[i] / 2 ? ok : ng) = med; 
        }
        ll lo = sum[ok], ro = sum[i] - sum[ok];
        ll ln = sum[ng], rn = sum[i] - sum[ng];
        m = max(lo, rn);
        M = min(ro, ln);
        // eprintf("%d : %d %d -> %lld %lld, ", i, ok, ng, M, m);
        eprintf("(%lld,%lld) (%lld,%lld) => %lld,%lld : ", lo, ro, ln, rn, m, M);

        ok = i, ng = n;
        while (ng - ok > 1) {
            int med = (ng + ok) / 2;
            (sum[med] <= (sum[i] + sum[n]) / 2 ? ok : ng) = med; 
        }
        lo = sum[ok] - sum[i], ro = sum[n] - sum[ok];
        ln = sum[ng] - sum[i], rn = sum[n] - sum[ng];
        chmin(m, max(lo, rn));
        chmax(M, min(ro, ln));
        // eprintf("%d %d -> %lld %lld\n", ok, ng, M, m);
        eprintf("(%lld,%lld) (%lld,%lld) => %lld,%lld\n", lo, ro, ln, rn, m, M);

        chmin(ans, M - m);
    }
    cout << ans << "\n";
    return 0;
}