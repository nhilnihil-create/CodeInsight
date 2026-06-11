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

#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define repp(i, m, n) for(int i = m, i##_len = (n); i < i##_len; ++i)
#define reprev(i, n) for(ll i = (n-1LL); i >= 0; --i)
#define all(x) (x).begin(), (x).end()
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <ll,ll> P;
typedef long double ld;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep (i, n) cin >> a[i];
    ll sum[1000][1000] = {};
    rep (i, n) {
        rep (j, n) {
            sum[i][j] = (i > j ? sum[i - 1][j] : 0) + (i >= j ? a[i] : 0);
            eprintf("%3lld ", sum[i][j]);
        }
        eprintf("\n");
    }
    int m = 40;
    ll ans = 0;
    reprev(x, m) {
        int count = 0;
        ll tmp = ans + (1LL << x);
        rep (i, n) {
            rep (j, n) {
                if (i >= j && (sum[i][j] & tmp) == tmp) {
                    count++;
                }
            }
        }
        if (count >= k) ans = tmp;
    }
    cout << ans << "\n";
    return 0;
}