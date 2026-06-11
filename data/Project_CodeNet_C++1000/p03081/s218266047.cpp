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
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return 1;} return 0; }
template<class T> bool chmin(T &a, const T &b) {if (a > b) {a = b; return 1;} return 0; }
#define INF 0x7FFFFFFF
#define LINF 0x7FFFFFFFFFFFFFFFLL
#define Yes(q) (q ? "Yes" : "No")
#define YES(q) (q ? "YES" : "NO")
#define DUMP(q) cerr << "[DEBUG] " #q ": " << (q) << " at " __FILE__ ":" << __LINE__ << endl
#define DUMPALL(q) cerr << "[DEBUG] " #q ": ["; REP(dumpall_i, (q).size()) { cerr << q[dumpall_i] << (dumpall_i == (q).size() - 1 ? "" : ", "); } cerr << "] at " __FILE__ ":" << __LINE__ << endl

// gcc拡張マクロ
#define gcd __gcd
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll

// エイリアス
using  ll = long long;
using ull = unsigned long long;
using  ld = long double;
using namespace std;

// モジュール
ll test(ll i, string &s, vector<char> &t, vector<char> &d) {
    ll q = t.size(), n = s.size();
    REP(j, q) {
        if (s[i] == t[j]) {
            switch (d[j]) {
                case 'L':
                    i--;
                    break;
                case 'R':
                    i++;
                    break;
            }
        }
        if (i < 0 || n <= i) break;
    }
    return i;
}

// 処理内容
int main() {
    
    ll n, q;
    string s;
    cin >> n >> q >> s;
    vector<char> t(q), d(q);
    REP(i, q) cin >> t[i] >> d[i];

    ll lng = -1, lok = n;
    while (abs(lok - lng) > 1) {
        ll lmd = (lng + lok) / 2;
        if (test(lmd, s, t, d) < 0) {
            lng = lmd;
        } else {
            lok = lmd;
        }
    }
    ll rng = n, rok = -1;
    while (abs(rok - rng) > 1) {
        ll rmd = (rng + rok) / 2;
        if (test(rmd, s, t, d) >= n) {
            rng = rmd;
        } else {
            rok = rmd;
        }
    }

    cout << max(0LL, rok - lok + 1) << endl;
    
}