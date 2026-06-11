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
    string s; cin >> s;
    ll q; cin >> q;
    vector<ll> k(q);
    REP(i, q) cin >> k[i];

    REP(t, q) {

        ll ans = 0;
        ll dnum = 0, mnum = 0, dmnum = 0;
        REP(i, n) {
            if (i - k[t] >= 0) {
                switch (s[i-k[t]]) {
                    case 'D':
                        --dnum;
                        dmnum -= mnum;
                        break;
                    case 'M':
                        --mnum;
                        break;
                    case 'C':
                        // do nothing
                        break;
                }
            }
            switch (s[i]) {
                case 'D':
                    ++dnum;
                    break;
                case 'M':
                    ++mnum;
                    dmnum += dnum;
                    break;
                case 'C':
                    ans += dmnum;
                    break;
            }
        }
        cout << ans << endl;

    }
    
}