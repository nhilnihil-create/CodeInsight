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
#define reprev(i, n) for(int i = (n-1LL); i >= 0; --i)
#define all(x) (x).begin(), (x).end()
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> P;
typedef long double ld;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, k; cin >> n >> k;
    ll ans = (ll)1e19;
    vector<P> p(n); rep (i, n) cin >> p[i].first >> p[i].second;
    rep (x1, n) {
        repp (x2, x1 + 1, n) {
            rep (y1, n) {
                repp (y2, y1 + 1, n) {
                    int h1 = p[x1].first, h2 = p[x2].first, w1 = p[y1].second, w2 = p[y2].second;
                    if (h1 > h2) swap(h1, h2); if (w1 > w2) swap(w1, w2);
                    int tmp = 0;
                    rep (i, n) {
                        if (h1 <= p[i].first && p[i].first <= h2
                         && w1 <= p[i].second && p[i].second <= w2) {
                            tmp++;
                        }
                    }
                    eprintf("%lld x:(%d,%d) y:(%d,%d)\n", (ll)(h2 - h1) * (w2 - w1), h1, h2, w1, w2);
                    if (tmp >= k) chmin(ans, (ll)(h2 - h1) * (w2 - w1));
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}