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
typedef pair <int,int> P;
typedef long double ld;
const int MOD = 1000000007;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> c(n);
    rep (i, n) {
        cin >> c[i];
        c[i]--;
    }
    vector<int> prev(200000);
    vector<P> sec;
    rep (i, n) {
        if (prev[c[i]] != 0 && prev[c[i]] != i) sec.push_back(make_pair(prev[c[i]], i));
        prev[c[i]] = i + 1;
    }
    sort(all(sec));
    for (P section: sec) eprintf("(%d,%d)", section.first, section.second); eprintf("\n");
    vector<int> ans(n);
    ans[0] = 1;
    int now = 0, nowmax = sec.size();
    repp (i, 1, n) {
        ans[i] = (ans[i] + ans[i - 1]) % MOD;
        if (now != nowmax && sec[now].first == i) {
            ans[sec[now].second] += ans[i - 1];
            now++;
        }
    }
    rep (i, n) eprintf("%d ", ans[i]); eprintf("\n");
    cout << ans[n - 1] << "\n";
    return 0;
}