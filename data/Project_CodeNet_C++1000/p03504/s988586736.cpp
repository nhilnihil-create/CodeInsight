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
typedef pair <P,int> PP;
typedef long double ld;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, c; cin >> n >> c;
    vector<PP> stc;
    vector<bitset<31> > end(100002);
    int imos[100002] = {};
    rep (i, n) {
        int p, q, r; cin >> p >> q >> r;
        stc.emplace_back(make_pair(p, q), r);
    }
    sort(all(stc), [](PP a, PP b){return a.first.second < b.first.second;});
    rep (i, n) {
        int q = stc[i].first.second, r = stc[i].second;
        end[q].set(r);
    }
    rep (i, n) {
        int p = stc[i].first.first, q = stc[i].first.second, r = stc[i].second;
        if (end[p][r]) imos[p + 1]++;
        else imos[p]++;
        imos[q + 1]--;
        eprintf("%d %d %d\n", end[p][r] * 1, p, q);
    }
    int ans = imos[0];
    repp (i, 1, 100002) {
        imos[i] += imos[i - 1]; 
        chmax(ans, imos[i]);
    }
    cout << ans << "\n";
    return 0;
}