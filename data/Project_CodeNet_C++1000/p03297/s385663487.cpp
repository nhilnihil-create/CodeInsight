#pragma GCC optimize ("O3")
#pragma GCC target ("tune=native")
#pragma GCC target ("avx")

#include <bits/stdc++.h>

// 汎用マクロ
#define ALL_OF(x) (x).begin(), (x).end()
#define REP(i,n) for (unsigned long long i=0, i##_len=(n); i<i##_len; i++)
#define RANGE(i,is,ie) for (unsigned long long i=(is), i##_end=(ie); i<=i##_end; i++)
#define UNIQUE(v) (v).erase(unique((v).begin(), (v).end()), (v).end())
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


// 処理内容
int main() {
    
    int t;
    string ans;
    cin >> t;
    REP(i, t) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a < b || d < b) {
            ans += "No\n";
        } else if (c >= b) {
            ans += "Yes\n";
        } else {
            if (a % b > c) {
                ans += "No\n";
            } else {
                ll g = gcd(b, d);
                ll amax = a % g + (b - g);
                ans += amax > c ? "No\n" : "Yes\n";
            }
        }
    }
    cout << ans << flush;
    
}