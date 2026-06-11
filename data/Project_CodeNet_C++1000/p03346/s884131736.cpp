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
typedef pair <ll,ll> P;
typedef long double ld;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> p(n), invp(n);
    rep (i, n) {
        cin >> p[i];
        p[i]--;
        invp[p[i]] = i;
    }
    vector<int> inv_left(n - 1), inv_right(n - 1);
    rep (i, n - 1) {
        if (i == 0) inv_left[0] = (invp[0] > invp[1] ? 0 : -1);
        else inv_left[i] = (invp[i] > invp[i + 1] ? i : inv_left[i - 1]);
    }
    reprev (i, n - 1) {
        if (i == n - 2) inv_right[n - 2] = (invp[n - 2] > invp[n - 1] ? n - 2 : n - 1);
        else inv_right[i] = (invp[i] > invp[i + 1] ? i : inv_right[i + 1]);
    }
    int ans = n - 1;
    rep (i, n) eprintf("%d ", invp[i]); eprintf("\n");
    rep (i, n - 1) { // 0-i,i+1-n-1
        if (invp[i] > invp[i + 1]) continue;
        eprintf("%d/%d: ", i, i + 1);
        int tmp = 0;
        tmp += inv_left[i] + 1;
        tmp += n - (inv_right[i] + 1);
        eprintf(" -> %d\n", tmp);
        chmin(ans, tmp);
    }
    cout << ans << "\n";
    return 0;
}