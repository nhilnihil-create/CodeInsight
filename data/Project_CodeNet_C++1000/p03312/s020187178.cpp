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
    
    ll n; cin >> n;
    vector<ll> a(n);
    REP(i, n) cin >> a[i];

    vector<ll> imos(n+1, 0);
    REP(i, n) imos[i+1] = imos[i] + a[i];

    ll ans = INF;
    RANGE(rb, 2, n-2) {

        const ll pq = imos[rb];
        const ll rs = imos[n] - imos[rb];

        const auto qb0 = upper_bound(imos.begin(), imos.begin() + rb, pq/2);
        const auto qb1 = qb0 - 1;
        const auto qbitr = abs(pq - *qb0 * 2) <= abs(pq - *qb1 * 2) ? qb0 : qb1;
        const ll qb = qbitr - imos.begin();

        const auto sb0 = upper_bound(imos.begin() + rb, imos.end(), pq + rs/2);
        const auto sb1 = sb0 - 1;
        const auto sbitr = abs(rs - (*sb0 - imos[rb]) * 2) <= abs(rs - (*sb1 - imos[rb]) * 2) ? sb0 : sb1;
        const ll sb = sbitr - imos.begin();

        const ll p = imos[qb];
        const ll q = imos[rb] - imos[qb];
        const ll r = imos[sb] - imos[rb];
        const ll s = imos[n ] - imos[sb];
        
        const ll diff = max({p, q, r, s}) - min({p, q, r, s});
        chmin(ans, diff);
        
    }
    cout << ans << endl;
    
}