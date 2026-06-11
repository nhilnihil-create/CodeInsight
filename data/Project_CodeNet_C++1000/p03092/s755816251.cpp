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

    ll n, a, b;
    cin >> n >> a >> b;

    // p_i および番兵0, N+1
    vector<ll> p(n+2);
    p.front() = 0;
    RANGE(i, 1, n) cin >> p[i];
    p.back() = ++n;
    
    // 遷移 O(N^2)
    vector<ll> dp(n+1, LINF / 2); // dp[i] := {p_k|k<=i}が(狭義)単調増加（含番兵0）
    dp[0] = 0; // 初期状態：何もしなくても番兵は{0}で単調増加
    RANGE(i, 1, n) {
        ll term = 0;
        for (int j = i; j--; ) {
            if (p[j] < p[i]) {
                chmin(dp[i], dp[j] + term);
                term += b;
            } else {
                term += a;
            }
        }
    }

    cout << dp[n] << endl;
    
}