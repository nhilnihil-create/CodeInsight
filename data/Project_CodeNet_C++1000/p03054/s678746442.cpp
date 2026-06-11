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
    int h, w, n; cin >> h >> w >> n;
    int sr, sc; cin >> sr >> sc; sr--; sc--;
    string s, t; cin >> s >> t;
    
    int di[4] = {};
    const string dir = "ULDR";
    map<char, int> m; m['U'] = 0; m['L'] = 1; m['D'] = 2; m['R'] = 3;
    reprev (i, n) {
        di[(m[t[i]] + 2) % 4] = max(0, di[(m[t[i]] + 2) % 4] - 1);
        // if (abs(m[s[i]] - m[t[i]] == 2)) continue;
        di[m[s[i]]]++;
        if (di[0] >= h - di[2] || di[1] >= w - di[3]) {
            cout << "NO\n";
            return 0;
        }
    }
    int u = di[0], l = di[1], d = h - di[2], r = w - di[3];
    if (u <= sr && sr < d && l <= sc && sc < r) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}