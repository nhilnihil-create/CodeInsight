// May this submission get accepted!

#pragma GCC optimize ("O3")
#pragma GCC target ("tune=native")
#pragma GCC target ("avx")

#include <bits/stdc++.h>

// 汎用マクロ
#define ALL_OF(x) (x).begin(), (x).end()
#define REP(i,n) for (long long i=0, i##_len=(n); i<i##_len; i++)
#define RANGE(i,is,ie) for (long long i=(is), i##_end=(ie); i<=i##_end; i++)
#define DSRNG(i,is,ie) for (long long i=(is), i##_end=(ie); i>=i##_end; i--)
#define UNIQUE(v) do { sort((v).begin(), (v).end()); (v).erase(unique((v).begin(), (v).end()), (v).end()); } while (false)
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return true;} return false; }
template<class T> bool chmin(T &a, const T &b) {if (a > b) {a = b; return true;} return false; }
#define INF 0x7FFFFFFF
#define LINF 0x7FFFFFFFFFFFFFFFLL
#define Yes(q) ((q) ? "Yes" : "No")
#define YES(q) ((q) ? "YES" : "NO")
#define Possible(q) ((q) ? "Possible" : "Impossible")
#define POSSIBLE(q) ((q) ? "POSSIBLE" : "IMPOSSIBLE")
#define DUMP(q) cerr << "[DEBUG] " #q ": " << (q) << " at " __FILE__ ":" << __LINE__ << endl
#define DUMPALL(q) do { cerr << "[DEBUG] " #q ": ["; REP(i, (q).size()) { cerr << (q)[i] << (i == i_len-1 ? "" : ", "); } cerr << "] at " __FILE__ ":" << __LINE__ << endl; } while (false)
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

    ll n, m; cin >> n >> m;
    vector<ll> a(m);
    REP(i, m) cin >> a[i];
    vector<ll> d = {INF, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    sort(ALL_OF(a), greater<ll>());
    
    vector<ll> dp(n+1, -INF);
    dp[0] = 0;
    REP(i, n+1) {
        REP(j, m) if (i - d[a[j]] >= 0) {
            chmax(dp[i], dp[i - d[a[j]]] + 1);
        }
    }

    string s = "";
    for (ll i = n; i > 0; ) {
        REP(j, m) if (i - d[a[j]] >= 0) {
            if (dp[i] == dp[i - d[a[j]]] + 1) {
                i -= d[a[j]];
                s.push_back('0' + a[j]);
                break;
            }
        }
    }
    
    cout << s << '\n';
    
}