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
    ll n, k; cin >> n >> k;
    vector<P> su(n); for (auto &e : su) cin >> e.first >> e.second;
    sort(all(su), [](P a, P b){return (a.second!=b.second ? a.second>b.second : a.first>b.first);});
    ll base = 0, bonus = 0;
    stack<int> doubling;
    map<int, bool> used;
    rep (i, k) {
        base += (ll)su[i].second;
        if (used[su[i].first]) {
            doubling.push(i);
        } else {
            used[su[i].first] = true;
            bonus++;
        }
    }
    ll ans = base + bonus * bonus;
    eprintf("%lld %lld %lld\n", ans, base, bonus);
    rep (i, k, n) {
        if (doubling.empty()) break;
        if (used[su[i].first]) continue;
        int t = doubling.top(); doubling.pop();
        base += (ll)su[i].second - su[t].second;
        bonus++;
        used[su[i].first] = true;
        eprintf("%lld %lld %lld\n", base + bonus * bonus, base, bonus);
        chmax(ans, base + bonus * bonus);
    }
    cout << ans << "\n";
    return 0;
}