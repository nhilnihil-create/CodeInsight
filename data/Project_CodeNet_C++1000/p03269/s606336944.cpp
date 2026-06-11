#pragma GCC optimize ("O3")
#pragma GCC target ("tune=native")
#pragma GCC target ("avx")

#include <bits/stdc++.h>

// 汎用マクロ
#define ALL_OF(x) (x).begin(), (x).end()
#define REP(i,n) for (long long i=0, i##_len=(n); i<i##_len; i++)
#define RANGE(i,is,ie) for (long long i=(is), i##_end=(ie); i<=i##_end; i++)
#define DSRNG(i,is,ie) for (long long i=(is), i##_end=(ie); i>=i##_end; i--)
#define UNIQUE(v) { sort((v).begin(), (v).end()); (v).erase(unique((v).begin(), (v).end()), (v).end()); }
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return true;} return false; }
template<class T> bool chmin(T &a, const T &b) {if (a > b) {a = b; return true;} return false; }
#define INF 0x7FFFFFFF
#define LINF 0x7FFFFFFFFFFFFFFFLL
#define Yes(q) ((q) ? "Yes" : "No")
#define YES(q) ((q) ? "YES" : "NO")
#define Possible(q) ((q) ? "Possible" : "Impossible")
#define POSSIBLE(q) ((q) ? "POSSIBLE" : "IMPOSSIBLE")
#define DUMP(q) cerr << "[DEBUG] " #q ": " << (q) << " at " __FILE__ ":" << __LINE__ << endl
#define DUMPALL(q) { cerr << "[DEBUG] " #q ": ["; REP(i, (q).size()) { cerr << (q)[i] << (i == i_len-1 ? "" : ", "); } cerr << "] at " __FILE__ ":" << __LINE__ << endl; }
template<class T> T gcd(const T &a, const T &b) { return a < b ? gcd(b, a) : b ? gcd(b, a % b) : a; }
template<class T> T lcm(const T &a, const T &b) { return a / gcd(a, b) * b; }

// gcc拡張マクロ
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll

// エイリアス
#define DANCE_ long
#define ROBOT_ unsigned
#define HUMAN_ signed
#define CHOKUDAI_ const
using  ll = DANCE_ HUMAN_ DANCE_;
using ull = DANCE_ ROBOT_ DANCE_;
using cll = DANCE_ DANCE_ CHOKUDAI_;
using  ld = long double;
using namespace std;

// モジュール


// 処理内容
int main() {
    
    ll l; cin >> l;

    ll n = 0;
    for(ll i = 1; i <= l; i *= 2, ++n);

    vector<tuple<ll, ll, ll>> ans;
    RANGE(i, 1, n-1) {
        ans.emplace_back(i, i+1, 0);
        ans.emplace_back(i, i+1, 1LL << n-i-1);
    }
    for (ll i = 0, mask = 1; i < n-1; ++i, mask <<= 1) {
        if (mask & l) {
            ans.emplace_back(1, n-i, l & ~((mask << 1) - 1));
        }
    }

    cout << n << " " << ans.size() << endl;
    REP(i, ans.size()) {
        cout << get<0>(ans[i]) << " ";
        cout << get<1>(ans[i]) << " ";
        cout << get<2>(ans[i]) << "\n";
    }
    
}