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
    string s; cin >> s;
    int y, x; cin >> x >> y;
    bool dir = false, first = true;
    bool dp[2][16004] = {}, tmp[2][16004] = {};
    dp[0][8002] = dp[1][8002] = true;
    int count = 0;
    rep (i, s.size() + 1) {
        if (i == i_len - 1 || s[i] == 'T') {
            rep (i, 16004) tmp[dir][i] = false;
            rep (i, 16004 - count) tmp[dir][i + count] |= dp[dir][i];
            if (!first) repp (i, count, 16004) tmp[dir][i - count] |= dp[dir][i];
            rep (i, 16004) dp[dir][i] = tmp[dir][i];
            eprintf("(%d,%d)", dir, count);
            dir ^= true;
            first = false;
            count = 0;
        } else {
            count++;
        }
    }
    eprintf("\n");
    repp (i, 7997, 8007+1) eprintf("%d ", dp[0][i]); eprintf("\n");
    repp (i, 7997, 8007+1) eprintf("%d ", dp[1][i]); eprintf("\n");
    cout << ((dp[0][8002 + x] && dp[1][8002 + y]) ? "Yes" : "No") << "\n";
    return 0;
}