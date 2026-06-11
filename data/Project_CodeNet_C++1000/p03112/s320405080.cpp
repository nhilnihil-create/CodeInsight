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
    #define eprintf(...) 42
#endif

#define rep_(i, a_, b_, a, b, ...) for (int i = (a), i##_len = (b); i < i##_len; ++i)
#define rep(i, ...) rep_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define reprev_(i, a_, b_, a, b, ...) for (int i = (b-1), i##_min = (a); i >= i##_min; --i)
#define reprev(i, ...) reprev_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define all(x) (x).begin(), (x).end()
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
// template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> P;
typedef long double ld;

int main (void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a, b, q; cin >> a >> b >> q;
    vector<ll> s(a), t(b), x(q);
    for (ll &e : s) cin >> e; sort(all(s));
    for (ll &e : t) cin >> e; sort(all(t));
    for (ll &e : x) cin >> e;
    for (ll qu : x) {
        ll ans = (ll)1e18;
        auto ups = lower_bound(all(s), qu);
        auto upt = lower_bound(all(t), qu);
        int x = distance(s.begin(), ups), y = distance(t.begin(), upt);
        if (x > 0 && y > 0) chmin(ans, qu - min(s[x - 1], t[y - 1]));
        if (x > 0 && y < b) chmin(ans, t[y] - s[x - 1] + min(t[y] - qu, qu - s[x - 1]));
        if (x < a && y > 0) chmin(ans, s[x] - t[y - 1] + min(s[x] - qu, qu - t[y - 1]));
        if (x < a && y < b) chmin(ans, max(s[x], t[y]) - qu);
        cout << ans << "\n";
    }
    return 0;
}